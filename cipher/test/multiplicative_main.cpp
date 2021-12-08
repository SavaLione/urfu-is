#include <cipher/multiplicative.h>
#include <iostream>

int main()
{
	multiplicative mp;
	mp.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
	mp.set_source_text("The quick brown fox jumps over the lazy dog 1234567890");
	mp.set_key("8");
	mp.encrypt();

	mp.print();
	std::cout << std::endl;

	mp.set_source_text("");
	mp.decrypt();

	mp.print();

	return 0;
}