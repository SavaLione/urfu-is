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

    std::cout << "source: " << vr.get_source_text() << std::endl;
    std::cout << "cipher: " << vr.get_cipher_text() << std::endl;
    std::cout << std::endl;

    vr.set_source_text("");
    vr.decrypt();

    std::cout << "source: " << vr.get_source_text() << std::endl;
    std::cout << "cipher: " << vr.get_cipher_text() << std::endl;

    return 0;
}

/*
text: [ATTACKATDAWN]
k:    [LEMON]
k_ph: [LEMONLEMONLE]

sh_t: [LXFOPVEFRNHR]

ans:  [ATTACKATDAWN]
*/
// int main()
// {
//     std::string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     std::cout << "[" << al << "]" << std::endl;
//     std::cout << std::endl;

//     for (int x = 0; x < al.size(); x++)
//     {
//         for (int y = 0; y < al.size(); y++)
//         {
//             std::cout << al[(x + y) % al.size()];
//         }
//         std::cout << std::endl;
//     }

//     std::string text = "ATTACKATDAWN";
//     std::string k = "LEMON";
//     std::string k_ph = "";

//     for (int i = 0; i < text.size(); i++)
//     {
//         k_ph += k[i % k.size()];
//     }

//     std::cout << std::endl;
//     std::cout << "text: " << "[" << text << "]" << std::endl;
//     std::cout << "k:    " << "[" << k << "]" << std::endl;
//     std::cout << "k_ph: " << "[" << k_ph << "]" << std::endl;
//     std::cout << std::endl;

//     std::string sh_t = "";

//     for (int i = 0; i < k_ph.size(); i++)
//     {
//         int res = 0;
//         for (int z = 0; z < al.size(); z++)
//         {
//             if (al[z] == text[i])
//             {
//                 res += z;
//             }

//             if (al[z] == k_ph[i])
//             {
//                 res += z;
//             }
//         }

//         sh_t += al[res % al.size()];
//     }

//     std::cout << "sh_t: " << "[" << sh_t << "]" << std::endl;
//     std::cout << std::endl;

//     std::string ans = "";
    
//     for (int i = 0; i < sh_t.size(); i++)
//     {
//         int ret = 0;

//         for (int z = 0; z < al.size(); z++)
//         {
//             if (al[z] == sh_t[i])
//             {
//                 ret += z;
//             }

//             if (al[z] == k_ph[i])
//             {
//                 ret -= z;
//             }
//         }

//         ret += al.size();
//         ret = ret % al.size();
//         ans += al[ret];
//     }

//     std::cout << "ans:  " << "[" << ans << "]" << std::endl;

//     return 0;
// }

/*
    n   al.size();
    ci  sh_t[i];
    mi  text[i]
    ki  k_ph[i]
*/