#include "core/affine.h"

affine::affine()
{
}

affine::~affine()
{
}

std::string affine::get_source_text()
{
    return _source_text;
}

std::string affine::get_cipher_text()
{
    return _cipher_text;
}

std::string affine::get_alphabet()
{
    return _alphabet;
}

void affine::set_alphabet(std::string alphabet)
{
    _alphabet = alphabet;
}

void affine::set_source_text(std::string source_text)
{
    _source_text = source_text;
}

void affine::set_cipher_text(std::string cipher_text)
{
    _cipher_text = cipher_text;
}

int affine::get_power()
{
    return _alphabet.size();
}

int affine::_find(char character)
{
    int found = _alphabet.find(character);
    return found;
}

void affine::set_key_a(std::string key_a)
{
    int ret = 0;
    if (key_a == "")
    {
        return;
    }

    try
    {
        ret = std::stoi(key_a);
    }
    catch (const std::exception &e)
    {
        ret = 0;
        // spdlog::error(e.what());
    }

    _key_a = ret;
}

void affine::set_key_b(std::string key_b)
{
    int ret = 0;
    if (key_b == "")
    {
        return;
    }

    try
    {
        ret = std::stoi(key_b);
    }
    catch (const std::exception &e)
    {
        ret = 0;
        // spdlog::error(e.what());
    }

    _key_b = ret;
}

std::string affine::get_key_a()
{
    return std::to_string(_key_a);
}

std::string affine::get_key_b()
{
    return std::to_string(_key_b);
}

void affine::encrypt()
{
    _cipher_text = "";
    int power = get_power();
    for (int i = 0; i < _source_text.size(); i++)
    {
        _cipher_text += _find_char((_key_a * _find(_source_text[i]) + _key_b) % power);
    }
}

void affine::decrypt()
{
    _source_text = "";
    int power = get_power();
    int inverse = _modular_inverse(_key_a, power);
    for (int i = 0; i < _cipher_text.size(); i++)
    {
        // _source_text += (char)(inverse * (power + _cipher_text[i] - _key_b) % power);
        // std::cout << (char)(modInverse(a, 26) * (26 + input[i] - 'a' - b) % 26 + 'a');
        _source_text += _find_char(inverse * ((power + _find(_cipher_text[i]) - _key_b) % power));
    }
}

int affine::gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int affine::_modular_inverse(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1)
    {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0)
        x1 += b0;
    return x1;
}

char affine::_find_char(int ch)
{
    return _alphabet[ch % get_power()];
    //return _alphabet[ch];
}