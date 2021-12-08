#include "cipher/transposition.h"

transposition::transposition()
{
	_set_name("transposition");
	_set_description("transposition cipher");
}

transposition::~transposition()
{
}

void transposition::set_key(std::string const &key)
{
	_key = key;
	_set_permutation_order();
}

void transposition::_set_permutation_order()
{
	// Add the permutation order into map
	for(int i = 0; i < _key.length(); i++)
	{
		_key_map[_key[i]] = i;
	}
}

std::string transposition::_encrypt_message(std::string msg)
{
	int row, col, j;
	std::string cipher = "";

	/* calculate column of the matrix*/
	col = _key.length();

	/* calculate Maximum row of the matrix*/
	row = msg.length() / col;

	if(msg.length() % col)
	{
		row += 1;
	}

	char matrix[row][col];

	for(int i = 0, k = 0; i < row; i++)
	{
		for(int j = 0; j < col;)
		{
			if(msg[k] == '\0')
			{
				/* Adding the padding character '_' */
				matrix[i][j] = '_';
				j++;
			}

			if(isalpha(msg[k]) || msg[k] == ' ')
			{
				/* Adding only space and alphabet into matrix*/
				matrix[i][j] = msg[k];
				j++;
			}
			k++;
		}
	}

	for(std::map<int, int>::iterator ii = _key_map.begin(); ii != _key_map.end(); ++ii)
	{
		j = ii->second;

		// getting cipher text from matrix column wise using permuted key
		for(int i = 0; i < row; i++)
		{
			if(isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
			{
				cipher += matrix[i][j];
			}
		}
	}

	return cipher;
}

std::string transposition::_decrypt_message(std::string cipher)
{
	/* calculate row and column for cipher Matrix */
	int col = _key.length();

	int row = cipher.length() / col;
	char cipherMat[row][col];

	/* add character into matrix column wise */
	for(int j = 0, k = 0; j < col; j++)
	{
		for(int i = 0; i < row; i++)
		{
			cipherMat[i][j] = cipher[k++];
		}
	}

	/* update the order of key for decryption */
	int index = 0;
	for(std::map<int, int>::iterator ii = _key_map.begin(); ii != _key_map.end(); ++ii)
	{
		ii->second = index++;
	}

	/* Arrange the matrix column wise according 
    to permutation order by adding into new matrix */
	char decCipher[row][col];
	std::map<int, int>::iterator ii = _key_map.begin();
	int k							= 0;
	for(int l = 0, j; _key[l] != '\0'; k++)
	{
		j = _key_map[_key[l++]];
		for(int i = 0; i < row; i++)
		{
			decCipher[i][k] = cipherMat[i][j];
		}
	}

	/* getting Message using matrix */
	std::string msg = "";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(decCipher[i][j] != '_')
			{
				msg += decCipher[i][j];
			}
		}
	}
	return msg;
}

void transposition::encrypt()
{
	_cipher_text = _encrypt_message(_source_text);
}

void transposition::decrypt()
{
	_source_text = _decrypt_message(_cipher_text);
}