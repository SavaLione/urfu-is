/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_ADDITIVE_H
#define CIPHER_ADDITIVE_H

#include "cipher/key.h"

class additive : public key
{
public:
	additive();
	~additive();

	void set_key(std::string const &key);
	std::string get_key();

	void encrypt();
	void decrypt();

private:
	int _i_key = 0;
	int _find(char character);
};

#endif // CIPHER_ADDITIVE_H