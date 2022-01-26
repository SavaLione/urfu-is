#include "cipher/vigenere.h"

vigenere::vigenere()
{
	_set_name("vigenere");
	_set_description("vigenere cipher");
}

vigenere::~vigenere()
{
}

void vigenere::encrypt()
{
	_cipher_text = "";
	_key_ph = "";

	for(int i = 0; i < _source_text.size(); i++)
	{
		_key_ph += _key[i % _key.size()];
	}

	for(int i = 0; i < _key_ph.size(); i++)
	{
		int res = 0;
		for(int z = 0; z < _alphabet.size(); z++)
		{
			if(_alphabet[z] == _source_text[i])
			{
				res += z;
			}

			if(_alphabet[z] == _key_ph[i])
			{
				res += z;
			}
		}
		_cipher_text += _alphabet[res % _alphabet.size()];
	}
}

void vigenere::decrypt()
{
	_source_text = "";
	_key_ph = "";

	for(int i = 0; i < _cipher_text.size(); i++)
	{
		_key_ph += _key[i % _key.size()];
	}

	for(int i = 0; i < _cipher_text.size(); i++)
	{
		int res = 0;

		for(int z = 0; z < _alphabet.size(); z++)
		{
			if(_alphabet[z] == _cipher_text[i])
			{
				res += z;
			}

			if(_alphabet[z] == _key_ph[i])
			{
				res -= z;
			}
		}

		res += _alphabet.size();
		res = res % _alphabet.size();
		_source_text += _alphabet[res];
	}
}