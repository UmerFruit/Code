#include <iostream>
#include <openssl/bn.h>
using namespace std;
bool subset(string mainString, string subString)
{
    int mainLen = mainString.length();
    int subLen = subString.length();

    // Check if subString is longer than mainString
    if (subLen > mainLen)
        return false;

    for (int i = 0; i <= mainLen - subLen; ++i)
        // Check if the substring starting from index i in mainString is equal to subString
        if (mainString.substr(i, subLen) == subString)
            return true;

    // If no match is found
    return false;
}
int substr(string s1, string s2)
{
    int M = s1.length();
    int N = s2.length();
    for (int i = 0; i <= N - M; i++)
    {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
        if (j == M)
            return i;
    }
}
int main()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new(), *e = BN_new(), *M = BN_new(), *d = BN_new(), *signature = BN_new(), *verify = BN_new();

    BN_hex2bn(&n, "ADE82473F41437F39B9E2B57281C87BEDCB7DF38908C6E3CE657A078F775C2A2FEF56A6EF6004F28DBDE68866C4493B6B163FD14126BBF1FD2EA319B217ED1333CBA48F5DD79DFB3B8FF12F1219A4BC18A8671694A66666C8F7E3C70BFAD292206F3E4C0E680AEE24B8FB7997E94039FD347977C99482353E838AE4F0A6F832ED149578C8074B6DA2FD0388D7B0370211B75F2303CFA8FAEDDDA63ABEB164FC28E114B7ECF0BE8FFB5772EF4B27B4AE04C12250C708D0329A0E15324EC13D9EE19BF10B34A8C3F89A36151DEAC870794F46371EC2EE26F5B9881E1895C34796C76EF3B906279E6DBA49A2F26C5D010E10EDED9108E16FBB7F7A8F7C7E50207988F360895E7E237960D36759EFB0E72B11D9BBC03F94905D881DD05B42AD641E9AC0176950A0FD8DFD5BD121F352F28176CD298C1A80964776E4737BACEAC595E689D7F72D689C50641293E593EDD26F524C911A75AA34C401F46A199B5A73A516E863B9E7D72A712057859ED3E5178150B038F8DD02F05B23E7B4A1C4B730512FCC6EAE050137C439374B3CA74E78E1F0108D030D45B7136B407BAC130305C48B7823B98A67D608AA2A32982CCBABD83041BA2830341A1D605F11BC2B6F0A87C863B46A8482A88DC769A76BF1F6AA53D198FEB38F364DEC82B0D0A28FFF7DBE21542D422D0275DE179FE18E77088AD4EE6D98B3AC6DD27516EFFBC64F533434F"); // modulus of c2.pem

    BN_hex2bn(&signature, "0a73006c966eff0e52d0aedd8ce75a06ad2fa8e38fbfc90a031550c2e56c42bb6f9bf4b44fc244880875cceb079b14626e78deec27ba395cf5a2a16e5694701053b1bbe4afd0a2c32b01d496f4c5203533f9d86136e0718db4b8b5aa824595c0f2a92328e7d6a1cb6708daa0432caa1b931fc9def5ab695d13f55b865822ca4d55e470676dc257c5463941cf8a5883586d99fe57e8360ef00e23aafd8897d0e35c0e9449b5b51735d22ebf4e85ef18e08592eb063b6c29230960dc45024c12183be9fb0ededc44f85898aeeabd4545a1885d66cafe10e96f82c811420dfbe9ece38600de9d10e338faa47db1d8e8498284069b2be86b4f010c38772ef9dde739"); // signature of c2.pem

    BN_hex2bn(&e, "010001");
    // signature = message ^ d mod n
    // decrypt signature into verify
    BN_mod_exp(verify, signature, e, n, ctx);
    string hash = "1835ef034ca442c03e5c91a3f672e27c6a24397c86ea11b58d8bbd642dd99752";
    for (int i = 0; i < hash.length(); i++)
    {
        if (isalpha(hash[i]))
            hash[i] -= 32;
    }
    if (substr(hash, BN_bn2hex(verify)))
    {
        cout << "HASHES DONT MATCH" << endl;
    }
    else
    {
        cout << "HASHES MATCH" << endl;
    }
    cout << "Decrypted Signature = " << BN_bn2hex(verify) << endl;
    // cout << "signature = " << BN_bn2hex(signature) << endl;
    cout << "hash = " << hash << endl;

    return 0;
}