#include "core/hill.h"

int main()
{
    hill h;
    h.encryption();
    std::cout << "- - -" << std::endl;
    h.decryption();
    
    return 0;
}

// #include <iostream>
// #include <string>

// #include <Eigen/Dense>

// int get_num(std::string const &al, char const &ch);

// int main()
// {
//     std::string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     std::cout << "[" << al << "]" << std::endl;
//     std::cout << std::endl;

//     int m_size = 3; // Размер матрицы (m_size,m_size)

//     std::string key = "GYBNQKURP";
//     int key_matrix_size = sqrt(key.size());

//     std::string text = "ACT";

//     Eigen::MatrixXi matrix_k(key_matrix_size, key_matrix_size);
//     matrix_k.setZero();

//     for (int x = 0, i_key = 0; (x < matrix_k.cols()) && (i_key < key.size()); x++)
//     {
//         for (int y = 0; y < matrix_k.rows(); y++)
//         {
//             matrix_k(x, y) = get_num(al, key[i_key]);
//             i_key++;
//         }
//     }

//     std::cout << matrix_k << std::endl;
//     std::cout << std::endl;

//     Eigen::MatrixXi vec_text(text.size(), 1);
//     vec_text.setZero();

//     for (int i = 0; i < text.size(); i++)
//     {
//         vec_text(i, 0) = get_num(al, text[i]);
//     }

//     std::cout << vec_text << std::endl;
//     std::cout << std::endl;

//     Eigen::MatrixXi cipher_text(vec_text.cols(), vec_text.rows());
//     cipher_text.setZero();

//     cipher_text = matrix_k * vec_text;

//     std::cout << cipher_text << std::endl;
//     std::cout << std::endl;

//     for (int x = 0; x < cipher_text.cols(); x++)
//     {
//         for (int y = 0; y < cipher_text.rows(); y++)
//         {
//             cipher_text(y, x) = cipher_text(y, x) % al.size();
//         }
//     }

//     // for (int y = 0; y < cipher_text.rows(); y++)
//     // {
//     //     for (int x = 0; x < cipher_text.cols(); x++)
//     //     {
//     //         cipher_text(x, y) = cipher_text(x, y) % al.size();
//     //     }
//     // }

//     std::cout << cipher_text << std::endl;
//     std::cout << std::endl;

//     std::cout << "- - -" << std::endl;
//     std::cout << std::endl;

//     Eigen::MatrixXd test(8,8);
//     test = Eigen::MatrixXd::Random(8,8);

//     std::cout << test << std::endl;
//     std::cout << std::endl;
//     std::cout << test.inverse() << std::endl;
//     std::cout << std::endl;

//     return 0;
// }

// int get_num(std::string const &al, char const &ch)
// {
//     int ret = 0;
//     for (int i = 0; i < al.size(); i++)
//     {
//         if (al[i] == ch)
//         {
//             return i;
//         }
//     }

//     return ret;
// }