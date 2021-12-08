/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_AFFINE_H
#define CIPHER_AFFINE_H

#include "cipher/key.h"

class affine : public key
{
public:
	affine();
	~affine();

	void set_key(std::string const &key);

	void encrypt();
	void decrypt();

private:
	int _key_a = 3;
	int _key_b = 5;

	int _gcd(int a, int b);
	int _modular_inverse(int a, int m);
};

#endif // CIPHER_AFFINE_H