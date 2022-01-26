/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_AUTOKEY_H
#define CIPHER_AUTOKEY_H

#include "cipher/key.h"

class autokey : public key<std::string>
{
public:
	autokey();
	~autokey();

	void encrypt();
	void decrypt();

private:
	std::string _key_ph = "";
};

#endif // CIPHER_AUTOKEY_H