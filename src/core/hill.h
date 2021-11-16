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
    int _mod_inverse(int a, int m);
    void _get_cofactor(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &temp, int p, int q, int n);
    int _determinant(std::vector<std::vector<int>> &a, int n, int N);
    void _adjoint(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &adj, int N);
    bool _inverse(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &inv, int N);
};