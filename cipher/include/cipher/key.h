/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_KEY_H
#define CIPHER_KEY_H

#include <string>

class key
{
public:
	key();
	~key();

	virtual void encrypt();
	virtual void decrypt();

	virtual void set_alphabet(std::string const &alphabet);
	virtual void set_source_text(std::string const &source_text);
	virtual void set_cipher_text(std::string const &cipher_text);
	virtual void set_key(std::string const &key);

	virtual std::string get_name();
	virtual std::string get_description();
	virtual std::string get_alphabet();
	virtual std::string get_source_text();
	virtual std::string get_cipher_text();
	virtual std::string get_key();

	virtual int get_power();

	virtual void print();

protected:
	std::string _alphabet	 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string _source_text = "";
	std::string _cipher_text = "";
	std::string _key		 = "";

	void _set_name(std::string const &name);
	void _set_description(std::string const &description);

private:
	std::string _name		 = "name_not_set";
	std::string _description = "description not set";
};

#endif // CIPHER_KEY_H