#include <iostream>

#include "core/additive.h"

int main()
{
    additive ad;
    ad.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
    ad.set_source_text("The quick brown fox jumps over the lazy dog 1234567890          !@#$%^&*");
    ad.set_key(12);
    ad.encrypt();

    std::cout << "[" << ad.get_alphabet() << "]" << std::endl;
    std::cout << ad.get_source_text() << std::endl;
    std::cout << ad.get_cipher_text() << std::endl;

    ad.set_source_text("");
    ad.decrypt();
    std::cout << ad.get_source_text() << std::endl;
    std::cout << ad.get_cipher_text() << std::endl;

    return 0;
}