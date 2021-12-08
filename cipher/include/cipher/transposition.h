/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_TRANSPOSITION_H
#define CIPHER_TRANSPOSITION_H

#include "cipher/key.h"

#include <bits/stdc++.h>

class transposition : public key
{
public:
	transposition();
	~transposition();

	void encrypt();
	void decrypt();

	void set_key(std::string const &key);

private:
	void _set_permutation_order();
	std::string _encrypt_message(std::string msg);
	std::string _decrypt_message(std::string cipher);
	std::map<int, int> _key_map;
};

#endif // CIPHER_TRANSPOSITION_H