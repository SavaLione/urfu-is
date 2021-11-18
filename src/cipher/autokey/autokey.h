/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_AUTOKEY_AUTOKEY_H
#define CIPHER_AUTOKEY_AUTOKEY_H

#include <string>

class autokey
{
public:
    autokey();
    ~autokey();

    void set_key(std::string const& key);

    void encrypt();
    void decrypt();

    void set_alphabet(std::string alphabet);
    void set_source_text(std::string source_text);
    void set_cipher_text(std::string cipher_text);

    std::string get_alphabet();
    std::string get_source_text();
    std::string get_cipher_text();
    std::string get_key();

    int get_power();
private:
    std::string _alphabet;
    std::string _source_text;
    std::string _cipher_text;

    std::string _key;
    std::string _key_ph;
};

#endif // CIPHER_AUTOKEY_AUTOKEY_H