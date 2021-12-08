#include <cipher/transposition.h>
#include <iostream>

int main()
{
	transposition tp;
	tp.set_source_text("Geeks for Geeks");
	tp.set_key("HACK");

	tp.encrypt();

	tp.print();
	std::cout << std::endl;

	tp.set_source_text("");
	tp.decrypt();

	tp.print();

	return 0;
}
