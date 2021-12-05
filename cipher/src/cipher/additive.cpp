#include "cipher/additive.h"

#include <iostream>

additive::additive()
{
}

additive::~additive()
{
}

void additive::set_key(std::string key)
{
    int ret = 0;
    if (key == "")
    {
        return;
    }

    try
    {
        ret = std::stoi(key);
    }
    catch (const std::exception &e)
    {
        ret = 0;
        // spdlog::error(e.what());
    }

    ret = ret % get_power();
    _key = ret;
}

std::string additive::get_key()
{
    return std::to_string(_key);
}

void additive::encrypt()
{
    std::string cipher_text;
    for (int i = 0; i < get_power(); i++)
    {
        int z = _find(_source_text[i]);
        if ((z + _key) >= get_power())
        {
            int temp = (z + _key) - get_power();
            cipher_text += _alphabet[temp];
        }
        else
        {
            cipher_text += _alphabet[z + _key];
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
        if ((z - _key) < 0)
        {
            int temp = (z - _key) + get_power();
            decrypt_text += _alphabet[temp];
        }
        else
        {
            decrypt_text += _alphabet[z - _key];
        }
    }
    _source_text = decrypt_text;
}

int additive::_find(char character)
{
    int found = _alphabet.find(character);
    return found;
}