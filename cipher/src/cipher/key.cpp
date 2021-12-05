#include "cipher/key.h"

#include <iostream>

key::key()
{

}

key::~key()
{

}

void key::encrypt()
{}

void key::decrypt()
{}

void key::set_alphabet(std::string alphabet)
{
    _alphabet = alphabet;
}

void key::set_source_text(std::string source_text)
{
    _source_text = source_text;
}

void key::set_cipher_text(std::string cipher_text)
{
    _cipher_text = cipher_text;
}

void key::set_key(std::string const &key)
{
    _key = key;
}

std::string key::get_alphabet()
{
    return _alphabet;
}

std::string key::get_source_text()
{
    return _source_text;
}

std::string key::get_cipher_text()
{
    return _cipher_text;
}

std::string key::get_key()
{
    return _key;
}

int key::get_power()
{
    return _key.size();
}

void key::print()
{
    std::string ret = "";

    ret += "alphabet:     [";
    ret += _alphabet;
    ret += "]\n";

    ret += "_source_text: [";
    ret += _source_text;
    ret += "]\n";

    ret += "_cipher_text: [";
    ret += _cipher_text;
    ret += "]\n";

    ret += "_key:         [";
    ret += _key;
    ret += "]\n";

    std::cout << ret;
}