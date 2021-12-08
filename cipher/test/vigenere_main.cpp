#include <iostream>
#include <string>
#include <cipher/vigenere.h>

// Шифр Виженера

int main()
{
    vigenere vr;
    vr.set_alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    vr.set_source_text("ATTACKATDAWN");
    vr.set_key("LEMON");

    vr.encrypt();

    vr.print();

    std::cout << std::endl;

    vr.set_source_text("");
    vr.decrypt();

    vr.print();

    return 0;
}