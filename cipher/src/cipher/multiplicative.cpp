#include "cipher/multiplicative.h"
#include <string>

multiplicative::multiplicative()
{
    _set_name("multiplicative");
    _set_description("multiplicative cipher");
}

multiplicative::~multiplicative()
{
}

void multiplicative::set_key(std::string key)
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
    }

    _i_key = ret;

    _key = std::to_string(_i_key);
}

void multiplicative::encrypt()
{
    std::string cipher_text;
    int power = get_power();
    for (int i = 0; i < _source_text.size(); i++)
    {
        cipher_text += _alphabet[(_alphabet.find(_source_text[i]) * _i_key) % power];
    }
    _cipher_text = cipher_text;
}

void multiplicative::decrypt()
{
    std::string decrypt_text;
    int power = get_power();

    int inverse = _modular_inverse(_i_key, get_power());

    for (int i = 0; i < _cipher_text.size(); i++)
    {
        decrypt_text += _alphabet[(_alphabet.find(_cipher_text[i]) * inverse) % power];
    }

    _source_text = decrypt_text;
}

int multiplicative::_modular_inverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
    {
        return 0;
    }
 
    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
    {
        x += m0;
    }
 
    return x;
}