#include "cipher/autokey.h"

autokey::autokey()
{
    _set_name("autokey");
    _set_description("autokey cipher");
}

autokey::~autokey()
{
    
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