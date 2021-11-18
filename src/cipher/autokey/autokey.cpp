#include "cipher/autokey/autokey.h"

autokey::autokey()
{
}

autokey::~autokey()
{
}

void autokey::set_key(std::string const& key)
{
    _key = key;
}

void autokey::set_alphabet(std::string alphabet)
{
    _alphabet = alphabet;
}

void autokey::set_source_text(std::string source_text)
{
    _source_text = source_text;
}

void autokey::set_cipher_text(std::string cipher_text)
{
    _cipher_text = cipher_text;
}

std::string autokey::get_key()
{
    return _key;
}

std::string autokey::get_alphabet()
{
    return _alphabet;
}

std::string autokey::get_source_text()
{
    return _source_text;
}

std::string autokey::get_cipher_text()
{
    return _cipher_text;
}

void autokey::encrypt()
{
    _cipher_text = "";
    _key_ph = _key;
    for (int i = _key.size(), z = 0; i < _source_text.size(); i++, z++)
    {
        _key_ph += _source_text[z];
    }

    for (int i = 0; i < _key_ph.size(); i++)
    {
        int res = 0;
        for (int z = 0; z < _alphabet.size(); z++)
        {
            if (_alphabet[z] == _source_text[i])
            {
                res += z;
            }

            if (_alphabet[z] == _key_ph[i])
            {
                res += z;
            }
        }
        _cipher_text += _alphabet[res % _alphabet.size()];
    }
    
}

void autokey::decrypt()
{
    _source_text = "";
    // _key_ph = _key;
    // for (int i = _key.size(), z = 0; i < _cipher_text.size(); i++, z++)
    // {
    //     _key_ph += _cipher_text[z];
    // }

    for (int i = 0; i < _cipher_text.size(); i++)
    {
        int res = 0;
        for (int z = 0; z < _alphabet.size(); z++)
        {
            if (_alphabet[z] == _cipher_text[i])
            {
                res += z;
            }

            if (_alphabet[z] == _key_ph[i])
            {
                res -= z;
            }
        }
        res += _alphabet.size();
        res = res % _alphabet.size();
        _source_text += _alphabet[res];
    }
}