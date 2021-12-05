#include "cipher/playfair.h"
#include <vector>
#include <ctype.h>
#include <stdlib.h>

/**
 *  |/////////////////////////
 *  |       Algorithms       /
 *  |/////////////////////////
 */
static int Mod(int a, int b)
{
    return (a % b + b) % b;
}

static char **Create2DArray(int rowCount, int colCount)
{
    char **arr = new char *[rowCount];

    for (int i = 0; i < rowCount; ++i)
        arr[i] = new char[colCount];

    return arr;
}

static std::string ToUpper(std::string str)
{
    std::string output = str;
    int strLen = str.size();

    for (int i = 0; i < strLen; ++i)
        output[i] = toupper(output[i]);

    return output;
}

static std::string RemoveChar(std::string str, char ch)
{
    std::string output = str;

    for (int i = 0; i < output.size(); ++i)
        if (output[i] == ch)
            output = output.erase(i, 1);

    return output;
}

static std::vector<int> FindAllOccurrences(std::string str, char value)
{
    std::vector<int> indexes;

    int index = 0;
    while ((index = str.find(value, index)) != -1)
        indexes.push_back(index++);

    return indexes;
}

static std::string RemoveAllDuplicates(std::string str, std::vector<int> indexes)
{
    std::string retVal = str;

    for (int i = indexes.size() - 1; i >= 1; i--)
        retVal = retVal.erase(indexes[i], 1);

    return retVal;
}

static char **GenerateKeySquare(std::string key)
{
    char **keySquare = Create2DArray(5, 5);
    std::string defaultKeySquare = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    std::string tempKey = key.empty() ? "CIPHER" : ToUpper(key);

    tempKey = RemoveChar(tempKey, 'J');
    tempKey += defaultKeySquare;

    for (int i = 0; i < 25; ++i)
    {
        std::vector<int> indexes = FindAllOccurrences(tempKey, defaultKeySquare[i]);
        tempKey = RemoveAllDuplicates(tempKey, indexes);
    }

    tempKey = tempKey.substr(0, 25);

    for (int i = 0; i < 25; ++i)
        keySquare[(i / 5)][(i % 5)] = tempKey[i];

    return keySquare;
}

static void GetPosition(char **keySquare, char ch, int *row, int *col)
{
    if (ch == 'J')
        GetPosition(keySquare, 'I', row, col);

    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            if (keySquare[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
}

static char *SameRow(char **keySquare, int row, int col1, int col2, int encipher)
{
    return new char[2]{keySquare[row][Mod((col1 + encipher), 5)], keySquare[row][Mod((col2 + encipher), 5)]};
}

static char *SameColumn(char **keySquare, int col, int row1, int row2, int encipher)
{
    return new char[2]{keySquare[Mod((row1 + encipher), 5)][col], keySquare[Mod((row2 + encipher), 5)][col]};
}

static char *SameRowColumn(char **keySquare, int row, int col, int encipher)
{
    return new char[2]{keySquare[Mod((row + encipher), 5)][Mod((col + encipher), 5)], keySquare[Mod((row + encipher), 5)][Mod((col + encipher), 5)]};
}

static char *DifferentRowColumn(char **keySquare, int row1, int col1, int row2, int col2)
{
    return new char[2]{keySquare[row1][col2], keySquare[row2][col1]};
}

static std::string RemoveOtherChars(std::string input)
{
    std::string output = input;
    int strLen = input.size();

    for (int i = 0; i < strLen; ++i)
        if (!isalpha(output[i]))
            output = output.erase(i, 1);

    return output;
}

static std::string AdjustOutput(std::string input, std::string output)
{
    std::string retVal = output;
    int strLen = input.size();

    for (int i = 0; i < strLen; ++i)
    {
        if (!isalpha(input[i]))
            retVal = retVal.insert(i, 1, input[i]);

        if (islower(input[i]))
            retVal[i] = tolower(retVal[i]);
    }

    return retVal;
}

static std::string Cipher(std::string input, std::string key, bool encipher)
{
    std::string retVal = "";
    char **keySquare = GenerateKeySquare(key);
    std::string tempInput = RemoveOtherChars(input);
    int e = encipher ? 1 : -1;
    int tempInputLen = tempInput.size();

    if ((tempInputLen % 2) != 0)
        tempInput += "X";

    for (int i = 0; i < tempInputLen; i += 2)
    {
        int row1 = 0;
        int col1 = 0;
        int row2 = 0;
        int col2 = 0;

        GetPosition(keySquare, toupper(tempInput[i]), &row1, &col1);
        GetPosition(keySquare, toupper(tempInput[i + 1]), &row2, &col2);

        if (row1 == row2 && col1 == col2)
        {
            retVal += std::string(SameRowColumn(keySquare, row1, col1, e), 2);
        }
        else if (row1 == row2)
        {
            retVal += std::string(SameRow(keySquare, row1, col1, col2, e), 2);
        }
        else if (col1 == col2)
        {
            retVal += std::string(SameColumn(keySquare, col1, row1, row2, e), 2);
        }
        else
        {
            retVal += std::string(DifferentRowColumn(keySquare, row1, col1, row2, col2), 2);
        }
    }

    retVal = AdjustOutput(input, retVal);

    return retVal;
}

static std::string Encipher(std::string input, std::string key)
{
    return Cipher(input, key, true);
}

static std::string Decipher(std::string input, std::string key)
{
    return Cipher(input, key, false);
}
/**
 *  |/////////////////////////
 *  |       Algorithms       /
 *  |/////////////////////////
 */

playfair::playfair()
{
}

playfair::~playfair()
{
}

void playfair::set_key(std::string const &key)
{
    _key = key;
}

void playfair::set_source_text(std::string source_text)
{
    _source_text = source_text;
}

void playfair::set_cipher_text(std::string cipher_text)
{
    _cipher_text = cipher_text;
}

std::string playfair::get_key()
{
    return _key;
}

std::string playfair::get_source_text()
{
    return _source_text;
}

std::string playfair::get_cipher_text()
{
    return _cipher_text;
}

void playfair::encrypt()
{
    _cipher_text = Encipher(_source_text, _key);
}

void playfair::decrypt()
{
    _source_text = Decipher(_cipher_text, _key);
}