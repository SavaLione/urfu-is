#include "cipher/additive.h"

additive::additive()
{
	_set_name("additive");
	_set_description("additive cipher");
}

additive::~additive()
{
}

void additive::encrypt()
{
	std::string cipher_text;
	for(int i = 0; i < _source_text.size(); i++)
	{
		int z = _find(_source_text[i]);
		if((z + _key) >= get_power())
		{
			int temp = (z + _key) - get_power();
			cipher_text += _alphabet[temp];
		}
		else
		{
			cipher_text += _alphabet[z + _key];
		}
	}
	_cipher_text = cipher_text;
}

void additive::decrypt()
{
	std::string decrypt_text;
	for(int i = 0; i < _cipher_text.size(); i++)
	{
		int z = _find(_cipher_text[i]);
		if((z - _key) < 0)
		{
			int temp = (z - _key) + get_power();
			decrypt_text += _alphabet[temp];
		}
		else
		{
			decrypt_text += _alphabet[z - _key];
		}
	}
	_source_text = decrypt_text;
}

int additive::_find(char character)
{
	int found = _alphabet.find(character);
	return found;
}