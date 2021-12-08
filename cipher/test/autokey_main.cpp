#include <string>
#include <iostream>
#include <cipher/autokey.h>

int main()
{
    autokey ak;
    ak.set_alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ak.set_source_text("ATTACKATDAWN");
    ak.set_key("LEMON");
    ak.encrypt();

    ak.print();

    ak.decrypt();

    ak.print();

    return 0;
}