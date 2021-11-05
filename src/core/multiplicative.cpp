#include "core/multiplicative.h"

multiplicative::multiplicative()
{
}

multiplicative::~multiplicative()
{
}

std::string multiplicative::get_source_text()
{
    return _source_text;
}

std::string multiplicative::get_cipher_text()
{
    return _cipher_text;
}

std::string multiplicative::get_alphabet()
{
    return _alphabet;
}

void multiplicative::set_key(int key)
{
    _key = key;
}

int multiplicative::get_key()
{
    return _key;
}

void multiplicative::set_alphabet(std::string alphabet)
{
    _alphabet = alphabet;
}

void multiplicative::set_source_text(std::string source_text)
{
    _source_text = source_text;
}

void multiplicative::set_cipher_text(std::string cipher_text)
{
    _cipher_text = cipher_text;
}

int multiplicative::get_power()
{
    return _alphabet.size();
}

void multiplicative::encrypt()
{
    std::string cipher_text;
    int power = get_power();
    for (int i = 0; i < _source_text.size(); i++)
    {
        cipher_text += _alphabet[(_find(_source_text[i]) * _key) % power];
    }
    _cipher_text = cipher_text;
}

void multiplicative::decrypt()
{
    std::string decrypt_text;
    int power = get_power();

    // modular inverse
    /*
        Шаг первый:
        Находим инверсию ключу
    */

    // bool fl = true;
    // int inverse = -1;
    // for (int i = 0; (i < power) && (fl); i++)
    // {
    //     if (((_key * i) % power) == 1)
    //     {
    //         inverse = i;
    //         fl = false;
    //     }
    // }

    int inverse = _modular_inverse(_key, get_power());

    /*
        Либо так:
        inv[1] = 1;
            for(int i = 2; i < m; ++i)
            {
                inv[i] = m - (m/i) * inv[m%i] % m;
            }
        
        inv[i] = -[m/i] * inv[m mod i] mod m

        Доказательство:
        1. m mod i = m - [m/i] * i
        2. m mod i ≡ - [m/i] * i mod m
        3. (m mod i) * i ^ (-1) * (m mod i) ^ (-1) ≡ - [m/i] * i * i ^ (-1) mod m
        4. i ^ (-1) ≡ - [m/i] * (m mod i) ^ (-1) mod m
    */

    // decrypt
    /*
        Шаг второй:
        Находим расшифрованный текст по инверсии ключа
    */

    for (int i = 0; i < _cipher_text.size(); i++)
    {
        decrypt_text += _alphabet[(_find(_cipher_text[i]) * inverse) % power];
    }

    _source_text = decrypt_text;
}

int multiplicative::_find(char character)
{
    int found = _alphabet.find(character);
    return found;
}

std::string multiplicative::print()
{
    std::string ret;

    ret += "alphabet: [";
    ret += _alphabet;
    ret += "]\n";

    ret += "power: ";
    ret += std::to_string(get_power());
    ret += "\n";

    ret += "source text: ";
    ret += _source_text;
    ret += "\n";

    ret += "cipher text: ";
    ret += _cipher_text;
    ret += "\n\n";

    return ret;
}

int multiplicative::_modular_inverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
        return 0;
 
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
        x += m0;
 
    return x;
}