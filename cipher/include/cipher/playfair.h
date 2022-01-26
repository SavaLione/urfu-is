/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_PLAYFAIR_H
#define CIPHER_PLAYFAIR_H

#include "cipher/key.h"

class playfair : public key<std::string>
{
public:
	playfair();
	~playfair();

	void encrypt();
	void decrypt();
};

#endif // CIPHER_PLAYFAIR_H