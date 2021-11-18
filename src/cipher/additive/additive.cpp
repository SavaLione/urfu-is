#include "cipher/additive/additive.h"

#include <iostream>

additive::additive()
{
}

additive::~additive()
{
}

std::string additive::get_source_text()
{
    return _source_text;
}

std::string additive::get_cipher_text()
{
    return _cipher_text;
}

std::string additive::get_alphabet()
{
    return _alphabet;
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

    ret = ret % _alphabet.size();
    _key = ret;
}

std::string additive::get_key()
{
    return std::to_string(_key);
}

void additive::set_alphabet(std::string alphabet)
{
    _alphabet = alphabet;
}

void additive::set_source_text(std::string source_text)
{
    _source_text = source_text;
}

void additive::set_cipher_text(std::string cipher_text)
{
    _cipher_text = cipher_text;
}

int additive::get_power()
{
    return _alphabet.size();
}

void additive::encrypt()
{
    std::string cipher_text;
    for (int i = 0; i < _source_text.size(); i++)
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