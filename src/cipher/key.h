/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_KEY_H
#define CIPHER_KEY_H

#include <string>

class key
{
public:
    key();
    ~key();

    void encrypt();
    void decrypt();

    void set_alphabet(std::string alphabet);
    void set_source_text(std::string source_text);
    void set_cipher_text(std::string cipher_text);
    void set_key(std::string const& key);

    std::string get_alphabet();
    std::string get_source_text();
    std::string get_cipher_text();
    std::string get_key();

    int get_power();

    void print();

private:
    std::string _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string _source_text;
    std::string _cipher_text;
    std::string _key;
};

#endif // CIPHER_KEY_H