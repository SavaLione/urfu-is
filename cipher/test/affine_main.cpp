#include <cipher/affine.h>

#include <string>
#include <iostream>

int main()
{
    affine af;
    af.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .");
    af.set_source_text("The quick brown fox jumps over the lazy dog 1234567890");
    af.set_key("3 5");
    af.encrypt();

    af.print();
    std::cout << std::endl;

    af.set_source_text("");
    af.decrypt();
    af.print();

    return 0;
}