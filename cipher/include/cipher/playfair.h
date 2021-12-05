/*
 * Copyright (c) 2021, Savely Pototsky (SavaLione)
 * All rights reserved.
 */
#ifndef CIPHER_PLAYFAIR_H
#define CIPHER_PLAYFAIR_H

#include <string>

// void to_lower_case(char plain[], int ps);
// int remove_spaces(char *plain, int ps);
// void generate_key_table(char key[], int ks, char keyT[5][5]);
// void search(char keyT[5][5], char a, char b, int arr[]);
// int mod5(int a);
// int prepare(char str[], int ptrs);
// void encrypt(char str[], char keyT[5][5], int ps);
// void encrypt_by_playfair_cipher(char str[], char key[]);

class playfair
{
public:
    playfair();
    ~playfair();

    void set_key(std::string const& key);
    void set_source_text(std::string source_text);
    void set_cipher_text(std::string cipher_text);

    std::string get_key();
    std::string get_source_text();
    std::string get_cipher_text();

    void encrypt();
    void decrypt();

private:
    std::string _source_text = "";
    std::string _cipher_text = "";
    std::string _key = "";
};

#endif // CIPHER_PLAYFAIR_H