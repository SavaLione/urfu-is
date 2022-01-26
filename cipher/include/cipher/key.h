/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_KEY_H
#define CIPHER_KEY_H

#include <ostream>
#include <string>

struct key_ab
{
	int a;
	int b;
};

// inline std::ostream &operator<<(std::ostream &ret, key_ab const &k)
// {
// 	return ret << k.a << " " << k.b;
// }

template<typename T>
class key
{
public:
	key() {};
	~key() {}

	virtual void encrypt() {};
	virtual void decrypt() {};

	virtual void set_alphabet(std::string const &alphabet)
	{
		_alphabet = alphabet;
	}
	virtual void set_source_text(std::string const &source_text)
	{
		_source_text = source_text;
	}
	virtual void set_cipher_text(std::string const &cipher_text)
	{
		_cipher_text = cipher_text;
	}
	virtual void set_key(T const &k)
	{
		_key = k;
	}

	virtual std::string get_name()
	{
		return _name;
	}
	virtual std::string get_description()
	{
		return _description;
	}
	virtual std::string get_alphabet()
	{
		return _alphabet;
	}
	virtual std::string get_source_text()
	{
		return _source_text;
	}
	virtual std::string get_cipher_text()
	{
		return _cipher_text;
	}

	virtual T get_key()
	{
		return _key;
	}

	virtual int get_power()
	{
		return _alphabet.size();
	}

	virtual void print()
	{
	}

protected:
	std::string _alphabet	 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string _source_text = "";
	std::string _cipher_text = "";
	T _key;

	void _set_name(std::string const &name)
	{
		_name = name;
	}
	void _set_description(std::string const &description)
	{
		_description = description;
	}

private:
	std::string _name		 = "name_not_set";
	std::string _description = "description not set";
};

#endif // CIPHER_KEY_H