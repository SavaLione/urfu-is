/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_KEY_MGR_H
#define CIPHER_KEY_MGR_H

#include <cipher/additive.h>
#include <cipher/multiplicative.h>
#include <cipher/affine.h>
#include <cipher/autokey.h>
#include <cipher/playfair.h>
#include <cipher/vigenere.h>
//#include <cipher/hill.h>
#include <cipher/transposition.h>

#include <vector>

class key_mgr
{
public:
    key_mgr();
    ~key_mgr();

    void add_key(key const &k);

    void print();

private:
    std::vector<key> _keys;

    
};

#endif // CIPHER_KEY_MGR_H