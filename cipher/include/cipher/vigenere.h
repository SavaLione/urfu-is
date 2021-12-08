/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_VIGENERE_H
#define CIPHER_VIGENERE_H

#include "cipher/key.h"

class vigenere : public key
{
public:
	vigenere();
	~vigenere();

	void encrypt();
	void decrypt();

private:
	std::string _key_ph;
};

#endif // CIPHER_VIGENERE_H