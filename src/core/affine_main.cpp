#include "core/affine.h"

#include <string>
#include <iostream>

int main()
{
    affine af;
    af.set_alphabet("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .");
    af.set_source_text("The quick brown fox jumps over the lazy dog 1234567890");
    // af.set_alphabet("abcdefghijklmnopqrstuvwxyz");
    // af.set_source_text("savalione");
    // mp.set_alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // mp.set_source_text("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    af.set_key_a(3);
    af.set_key_b(5);
    af.encrypt();

    std::cout << af.print();

    af.set_source_text("");
    af.decrypt();
    std::cout << af.print();

    return 0;
}

// #include <algorithm>

// int gcd(int a, int b);
// int modInverse(int a, int b);

// int main()
// {
//     std::string choice;
//     do
//     {
//         std::cout << "Encrypt or Decrypt? [e/d] = ";
//         std::getline(std::cin, choice);
//         std::transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
//     } while (choice.length() > 1 || choice != "e" && choice != "d");

//     std::cout << "\nInput string: ";
//     std::string input;
//     std::getline(std::cin, input);

//     int a, b;
//     do
//     {
//         std::cout << "\na and b must be coprime\na = ";
//         std::cin >> a;
//         std::cout << "b = ";
//         std::cin >> b;
//     } while (std::cin.fail() || gcd(a, b) != 1);

//     std::cout << '\n';

//     if (choice == "e")
//     {
//         for (int i = 0; i < input.length(); ++i)
//         {
//             if (input[i] >= 'a' && input[i] <= 'z')
//             {
//                 std::cout << (char)((a * (input[i] - 'a') + b) % 26 + 'a');
//             }
//             else if (input[i] >= 'A' && input[i] <= 'Z')
//             {
//                 std::cout << (char)((a * (input[i] - 'A') + b) % 26 + 'A');
//             }
//             else
//             {
//                 std::cout << input[i];
//             }
//         }
//     }
//     else
//     {
//         for (int i = 0; i < input.length(); ++i)
//         {
//             if (input[i] >= 'a' && input[i] <= 'z')
//             {
//                 std::cout << (char)(modInverse(a, 26) * (26 + input[i] - 'a' - b) % 26 + 'a');
//             }
//             else if (input[i] >= 'A' && input[i] <= 'Z')
//             {
//                 std::cout << (char)(modInverse(a, 26) * (26 + input[i] - 'A' - b) % 26 + 'A');
//             }
//             else
//             {
//                 std::cout << input[i];
//             }
//         }
//     }

//     std::cout << '\n';
//     return 0;
// }

// int gcd(int a, int b)
// {
//     return b == 0 ? a : gcd(b, a % b);
// }

// int modInverse(int a, int b)
// {
//     int b0 = b, t, q;
//     int x0 = 0, x1 = 1;
//     if (b == 1)
//         return 1;
//     while (a > 1)
//     {
//         q = a / b;
//         t = b, b = a % b, a = t;
//         t = x0, x0 = x1 - q * x0, x1 = t;
//     }
//     if (x1 < 0)
//         x1 += b0;
//     return x1;
// }