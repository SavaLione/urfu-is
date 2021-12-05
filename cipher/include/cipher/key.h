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

    virtual void encrypt();
    virtual void decrypt();

    virtual void set_alphabet(std::string alphabet);
    virtual void set_source_text(std::string source_text);
    virtual void set_cipher_text(std::string cipher_text);
    virtual void set_key(std::string const& key);

    virtual std::string get_alphabet();
    virtual std::string get_source_text();
    virtual std::string get_cipher_text();
    virtual std::string get_key();

    virtual int get_power();

    virtual void print();

protected:
    std::string _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string _source_text;
    std::string _cipher_text;
    std::string _key;
};

#endif // CIPHER_KEY_H