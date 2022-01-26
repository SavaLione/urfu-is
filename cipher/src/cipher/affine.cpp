#include "cipher/affine.h"

affine::affine()
{
	_set_name("affine");
	_set_description("affine cipher");

	_key.a = 3;
	_key.b = 5;
}

affine::~affine()
{
}

void affine::encrypt()
{
	_cipher_text = "";
	int power	 = get_power();
	for(int i = 0; i < _source_text.size(); i++)
	{
		int char_pos = _alphabet.find(_source_text[i]);
		if(char_pos >= 0)
		{
			_cipher_text += _alphabet[((_key.a * char_pos + _key.b) % power) % power];
		}
	}
}

void affine::decrypt()
{
	_source_text = "";
	int power	 = get_power();
	int inverse	 = _modular_inverse(_key.a, power);
	for(int i = 0; i < _cipher_text.size(); i++)
	{
		int char_pos = _alphabet.find(_cipher_text[i]);
		if(char_pos >= 0)
		{
			_source_text += _alphabet[(inverse * ((power + char_pos - _key.b) % power)) % power];
		}
	}
}

int affine::_gcd(int a, int b)
{
	return b == 0 ? a : _gcd(b, a % b);
}

int affine::_modular_inverse(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if(b == 1)
		return 1;
	while(a > 1)
	{
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if(x1 < 0)
		x1 += b0;
	return x1;
}