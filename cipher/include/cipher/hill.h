/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_HILL_H
#define CIPHER_HILL_H

#include <string>
#include <vector>
#include <iostream>

class hill
{
public:
    hill();
    ~hill();
    void encryption();
    void decryption();

private:
    std::string _alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 .";

    int _mod_inverse(int a, int m);
    void _get_cofactor(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &temp, int p, int q, int n);
    int _determinant(std::vector<std::vector<int>> &a, int n, int N);
    void _adjoint(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &adj, int N);
    bool _inverse(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &inv, int N);

    int _get_num(char const& ch);
};

#endif // CIPHER_HILL_H