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

void affine::set_key_a(int key)
{
    _key_a = key;
}

void affine::set_key_b(int key)
{
    _key_b = key;
}

int affine::get_key_a()
{
    return _key_a;
}

int affine::get_key_b()
{
    return _key_b;
}

std::string affine::get_key_ab()
{
    std::string ret = std::to_string(_key_a);
    ret += " ";
    ret += std::to_string(_key_b);
    return ret;
}

void affine::encrypt()
{
    int power = get_power();
    for (int i = 0; i < _source_text.size(); i++)
    {
        _cipher_text += _find_char((_key_a * _find(_source_text[i]) + _key_b) % power);
    }
}

void affine::decrypt()
{
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

std::string affine::print()
{
    std::string ret;

    ret += "alphabet: [";
    ret += _alphabet;
    ret += "]\n";

    ret += "source text: ";
    ret += _source_text;
    ret += "\n";

    ret += "cipher text: ";
    ret += _cipher_text;
    ret += "\n";

    ret += "key a: ";
    ret += std::to_string(_key_a);
    ret += "\n";

    ret += "key b: ";
    ret += std::to_string(_key_b);
    ret += "\n\n";

    return ret;
}