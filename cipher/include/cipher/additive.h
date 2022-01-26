/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_ADDITIVE_H
#define CIPHER_ADDITIVE_H

#include "cipher/key.h"

class additive : public key<int>
{
public:
	additive();
	~additive();

	void encrypt();
	void decrypt();

private:
	int _find(char character);
};

#endif // CIPHER_ADDITIVE_H