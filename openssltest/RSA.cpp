#include <iostream>
#include <openssl/bn.h>
using namespace std;

void printBN(string msg, BIGNUM *a);
void task1();
void task2();
void task3();
void task4();

int main()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new(), *e = BN_new(), *M = BN_new(), *M2 = BN_new(), *d = BN_new(), *signature = BN_new(), *verify = BN_new();

    BN_hex2bn(&n, "AE1CD4DC432798D933779FBD46C6E1247F0CF1233595113AA51B450F18116115");
    BN_hex2bn(&signature, "867578747a8b4769830b757cadf0e8ddc3f3d67ace64f3ce255a0cfeacf2823d");
    BN_hex2bn(&M, "4c61756e63682061206d697373696c65"); // Launch a missile

    BN_hex2bn(&e, "010001");

    // signature = message ^ d mod n
    BN_mod_exp(verify, signature, e, n, ctx);

    printBN("M = ", M);
    
    printBN("signature = ", signature);
    printBN("verify = ", verify);
    //when changed from 2F to 3F the error occured
    //'utf-8' codec can't decode byte 0x91 in position 0: invalid start byte
    return 0;
}
void printBN(string msg, BIGNUM *a)
{
    /* Use BN_bn2hex(a) for hex string
     * Use BN_bn2dec(a) for decimal string */
    string number_str = BN_bn2hex(a);
    cout << msg;
    cout << number_str << endl;
}
void task1()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *p = BN_new();
    BIGNUM *q = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *phin = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *t[3] = {BN_new(), BN_new(), BN_new()};

    // BN_dec2bn(&p, "7");
    // BN_dec2bn(&q, "17");
    // BN_dec2bn(&e, "19");         //test case for RSA
    // BN_dec2bn(&t[0], "1");
    // Initialize p, q, n
    BN_hex2bn(&p, "F7E75FDC469067FFDC4E847C51F452DF");
    BN_hex2bn(&q, "E85CED54AF57E53E092113E62F436F4F");
    BN_hex2bn(&e, "0D88C3");
    BN_dec2bn(&t[0], "1");

    BN_sub(t[1], p, t[0]);
    BN_sub(t[2], q, t[0]); // calculate p-1 and q-1

    BN_mul(n, p, q, ctx);
    BN_mul(phin, t[1], t[2], ctx); // calculate n and phi(n)
    // given t[0], find b, such that t[0] * b mod n = 1
    // e^-1 mod (phi(n))
    // e(x) % phi(n) = 1
    BN_mod_inverse(d, e, phin, ctx);
    printBN("p = ", p);
    printBN("q = ", q);
    printBN("e = ", e);
    printBN("d = ", d);
}
void task2()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new();
    BIGNUM *e = BN_new();
    BIGNUM *M = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *cipher = BN_new();
    BIGNUM *decipher = BN_new();
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "4120746f702073656372657421");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    // res = a^c mod n
    // cipher = message ^ e mod n
    BN_mod_exp(cipher, M, e, n, ctx);
    BN_mod_exp(decipher, cipher, d, n, ctx);

    printBN("M = ", M);
    printBN("cipher = ", cipher);
    printBN("decipher = ", decipher);
}
void task3()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *cipher = BN_new();
    BIGNUM *M = BN_new();
    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&cipher, "8C0F971DF2F3672B28811407E2DABBE1DA0FEBBBDFC7DCB67396567EA1E2493F");
    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");
    // res = a^c mod n
    // cipher = message ^ e mod n
    BN_mod_exp(M, cipher, d, n, ctx);

    printBN("cipher = ", cipher);
    printBN("decipher = ", M);
    // print(bytes.fromhex("50617373776F72642069732064656573").decode("utf-8"))
    // Password is dees
}
void task4()
{
    BN_CTX *ctx = BN_CTX_new();
    BIGNUM *n = BN_new(), *e = BN_new(), *M = BN_new(), *M2 = BN_new(), *d = BN_new(), *signature = BN_new(), *signature2 = BN_new(), *verify = BN_new(), *verify2 = BN_new();

    BN_hex2bn(&n, "DCBFFE3E51F62E09CE7032E2677A78946A849DC4CDDE3A4D0CB81629242FB1A5");
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&M, "49206f776520796f75202432303030"); // I owe you $2000
    BN_hex2bn(&M2, "49206f776520796f75202433303030"); // I owe you $3000

    BN_hex2bn(&d, "74D806F9F3A62BAE331FFE3F0A68AFE35B3D2E4794148AACBC26AA381CD7D30D");

    // signature = message ^ d mod n
    BN_mod_exp(signature, M, d, n, ctx);
    BN_mod_exp(verify, signature, e, n, ctx);

    BN_mod_exp(signature2, M2, d, n, ctx);
    BN_mod_exp(verify2, signature2, e, n, ctx);

    printBN("M = ", M);
    
    printBN("signature = ", signature);
    printBN("verify = ", verify);
    cout<<endl;
    printBN("signature2 = ", signature2);
    printBN("verify2 = ", verify2); 
    //changing even one character completely changes the digital signature

}