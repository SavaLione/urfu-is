/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CORE_MULTIPLICATIVE_H
#define CORE_MULTIPLICATIVE_H

#include <string>

class multiplicative
{
public:
    multiplicative();
    ~multiplicative();

    std::string get_source_text();
    std::string get_cipher_text();
    std::string get_alphabet();

    void set_key(int key);
    int get_key();

    void encrypt();
    void decrypt();

    void set_alphabet(std::string alphabet);
    void set_source_text(std::string source_text);
    void set_cipher_text(std::string cipher_text);

    int get_power();

    std::string print();

private:
    std::string _alphabet;
    std::string _source_text;
    std::string _cipher_text;

    int _key = 0;

    int _find(char character);

    int _modular_inverse(int a, int m);
};

#endif // CORE_MULTIPLICATIVE_H