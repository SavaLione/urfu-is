#include <iostream>

#include <cipher/additive.h>

int main()
{
    additive ad;
    ad.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ");
    ad.set_source_text("The quick brown fox jumps over the lazy dog 1234567890          !@#$%^&*");
    ad.set_key("12");
    ad.encrypt();

    ad.print();
    std::cout << std::endl;

    ad.set_source_text("");
    ad.decrypt();
    ad.print();

    return 0;
}