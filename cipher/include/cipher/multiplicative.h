/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_MULTIPLICATIVE_H
#define CIPHER_MULTIPLICATIVE_H

#include "cipher/key.h"

class multiplicative : public key
{
public:
	multiplicative();
	~multiplicative();

	void encrypt();
	void decrypt();

	void set_key(std::string key);

private:
	int _i_key = 0;

	int _modular_inverse(int a, int m);
};

#endif // CIPHER_MULTIPLICATIVE_H