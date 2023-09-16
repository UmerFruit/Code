#include <iostream>
#include <cstring>
using namespace std;
string ceaserCipherDec(string cipher, int key = 3);
string ceaserCipherEnc(string input, int key = 3);
int main()
{
    string input = "INFORMATIONSECURITY";
    string cipher = ceaserCipherEnc(input);
    cout << cipher << endl;
    string decrypt = ceaserCipherDec(cipher);
    cout << decrypt << endl;

    // All possible Combinations Tester Code
    for (int i = 0; i < 26; i++)
    {
        cout << i + 1 << ". " << ceaserCipherDec(cipher, i) << endl;
    }
}

string ceaserCipherEnc(string input, int key)
{
    int len = input.length();
    string cipher = "";
    int minus;
    islower(input[0]) ? minus = 97 : minus = 65;
    for (int i = 0; i < len; i++)
    {
        char a = ((static_cast<int>(input[i] - minus) + key) % 26) + minus;
        cipher.push_back(a);
    }
    return cipher;
}
string ceaserCipherDec(string cipher, int key)
{
    int len = cipher.length();
    string original = "";
    int minus;
    islower(cipher[0]) ? minus = 97 : minus = 65;

    for (int i = 0; i < len; i++)
    {
        char a = ((static_cast<int>(cipher[i] - minus) - key + 26) % 26) + minus;
        original.push_back(a);
    }
    return original;
}
