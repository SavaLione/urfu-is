#include <iostream>

#include "core/multiplicative.h"

int main()
{
    multiplicative mp;
    mp.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
    mp.set_source_text("The quick brown fox jumps over the lazy dog 1234567890");
    // mp.set_alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // mp.set_source_text("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    mp.set_key(8);
    mp.encrypt();

    // std::cout << "[" << mp.get_alphabet() << "]" << std::endl;
    // std::cout << mp.get_source_text() << std::endl;
    // std::cout << mp.get_cipher_text() << std::endl;
    std::cout << mp.print();

    mp.set_source_text("");
    mp.decrypt();
    // std::cout << mp.get_source_text() << std::endl;
    // std::cout << mp.get_cipher_text() << std::endl;
    std::cout << mp.print();

    return 0;
}