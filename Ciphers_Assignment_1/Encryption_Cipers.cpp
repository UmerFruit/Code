#include <iostream>
#include <cstring>
using namespace std;
string subCipherDec(string cipher, int *key);
string subCipherEnc(string input, int *key);
int main()
{
    srand(time(0));
    string input = "hassansiddiqui";
    int len = input.length();
    int *key = new int[len];
    for (int i = 0; i < len; i++)
    {
        key[i] = rand() % 26;
    }
    string cipher = subCipherEnc(input, key);
    cout << cipher << endl;
    string decrypt = subCipherDec(cipher, key);
    cout << decrypt << endl;
    // code cracker with all possible combinations
    string original = "";
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
    
            char a = ((static_cast<int>(cipher[i] - 97) - j + 26) % 26) + 97;
            original.push_back(a);
        }
    }
}
string subCipherEnc(string input, int *key)
{
    int len = input.length();
    int minus = 97;
    string cipher = "";
    // key = new int[len];

    for (int i = 0; i < len; i++)
    {
        char a = ((static_cast<int>(input[i] - minus) + key[i]) % 26) + minus;
        cipher.push_back(a);
    }
    return cipher;
}
string subCipherDec(string cipher, int *key)
{
    int len = cipher.length();
    string original = "";
    int minus = 97;

    for (int i = 0; i < len; i++)
    {
        char a = ((static_cast<int>(cipher[i] - minus) - key[i] + 26) % 26) + minus;
        original.push_back(a);
    }
    return original;
}
