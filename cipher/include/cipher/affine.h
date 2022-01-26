/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_AFFINE_H
#define CIPHER_AFFINE_H

#include "cipher/key.h"

class affine : public key<key_ab>
{
public:
	affine();
	~affine();

	void encrypt();
	void decrypt();

private:
	int _gcd(int a, int b);
	int _modular_inverse(int a, int m);
};

#endif // CIPHER_AFFINE_H