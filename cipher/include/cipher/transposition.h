/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_TRANSPOSITION_H
#define CIPHER_TRANSPOSITION_H

#include <string>
#include <bits/stdc++.h>

class transposition
{
public:
    transposition();
    ~transposition();

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
private:
    std::string _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string _source_text;
    std::string _cipher_text;

    std::string _key;

    void _set_permutation_order();
    std::string _encrypt_message(std::string msg);
    std::string _decrypt_message(std::string cipher);
    std::map<int,int> _key_map;
};

#endif // CIPHER_TRANSPOSITION_H