/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CORE_AFFINE_H
#define CORE_AFFINE_H

#include <string>

class affine
{
public:
    affine();
    ~affine();

    std::string get_source_text();
    std::string get_cipher_text();
    std::string get_alphabet();

    void set_key_a(int key);
    void set_key_b(int key);
    int get_key_a();
    int get_key_b();
    std::string get_key_ab();

    int get_power();

    void encrypt();
    void decrypt();

    void set_alphabet(std::string alphabet);
    void set_source_text(std::string source_text);
    void set_cipher_text(std::string cipher_text);

    std::string print();

private:
    std::string _alphabet;
    std::string _source_text;
    std::string _cipher_text;

    int _key_a = 0;
    int _key_b = 0;

    int _find(char character);
    char _find_char(int ch);

    int gcd(int a, int b);
    int _modular_inverse(int a, int m);
};

#endif // CORE_AFFINE_H