#include <cipher/hill.h>

int main()
{
    hill h;
    h.encryption();
    std::cout << "- - -" << std::endl;
    h.decryption();

    return 0;
}