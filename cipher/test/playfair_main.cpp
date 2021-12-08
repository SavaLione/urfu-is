#include <cipher/playfair.h>
#include <iostream>
#include <string>

int main()
{
	playfair pf;

	pf.set_source_text("instruments");
	pf.set_key("Monarchy");

	pf.encrypt();

	pf.print();

	pf.decrypt();

	std::cout << std::endl;

	pf.print();

	return 0;
}