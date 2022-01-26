/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_MULTIPLICATIVE_H
#define CIPHER_MULTIPLICATIVE_H

#include "cipher/key.h"

class multiplicative : public key<int>
{
public:
	multiplicative();
	~multiplicative();

	void encrypt();
	void decrypt();

private:
	int _modular_inverse(int a, int m);
};

#endif // CIPHER_MULTIPLICATIVE_H