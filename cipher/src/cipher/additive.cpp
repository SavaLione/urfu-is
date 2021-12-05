#include "cipher/additive.h"
#include <stdlib.h>
#include <string>
#include <iostream>

additive::additive()
{
}

additive::~additive()
{
}

void additive::set_key(std::string const &key)
{
    int ret = 0;
    if (key == "")
    {
        _i_key = 0;
        return;
    }

    try
    {
        ret = std::stoi(key);
    }
    catch (...)
    {
        ret = 0;
    }

    ret = ret % get_power();
    _i_key = ret;
}

std::string additive::get_key()
{
    return std::to_string(_i_key);
}

void additive::encrypt()
{
    std::string cipher_text;
    for (int i = 0; i < _source_text.size(); i++)
    {
        int z = _find(_source_text[i]);
        if ((z + _i_key) >= get_power())
        {
            int temp = (z + _i_key) - get_power();
            cipher_text += _alphabet[temp];
        }
        else
        {
            cipher_text += _alphabet[z + _i_key];
        }
    }
    _cipher_text = cipher_text;
}

void additive::decrypt()
{
    std::string decrypt_text;
    for (int i = 0; i < _cipher_text.size(); i++)
    {
        int z = _find(_cipher_text[i]);
        if ((z - _i_key) < 0)
        {
            int temp = (z - _i_key) + get_power();
            decrypt_text += _alphabet[temp];
        }
        else
        {
            decrypt_text += _alphabet[z - _i_key];
        }
    }
    _source_text = decrypt_text;
}

int additive::_find(char character)
{
    int found = _alphabet.find(character);
    return found;
}