#include "core/affine.h"

#include <string>
#include <iostream>

int main()
{
    affine af;
    af.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .");
    af.set_source_text("The quick brown fox jumps over the lazy dog 1234567890");
    af.set_key_a("3");
    af.set_key_b("5");
    af.encrypt();

    std::cout << af.get_source_text() << std::endl;
    std::cout << af.get_cipher_text() << std::endl;
    std::cout << std::endl;

    af.set_source_text("");
    af.decrypt();
    std::cout << af.get_source_text() << std::endl;
    std::cout << af.get_cipher_text() << std::endl;

    return 0;
}