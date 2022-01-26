#include "cipher/key.h"
#include <cipher/affine.h>
#include <iostream>
#include <string>

int main()
{
	affine af;
	af.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .");
	af.set_source_text("The quick brown fox jumps over the lazy dog 1234567890");
	key_ab k_ab;
	k_ab.a = 3;
	k_ab.b = 5;
	af.set_key(k_ab);
	af.encrypt();

	af.print();
	std::cout << std::endl;

	af.set_source_text("");
	af.decrypt();
	af.print();

	return 0;
}