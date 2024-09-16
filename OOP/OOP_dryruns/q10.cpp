//---------------------Question # 10---------------------//
//-----Cross out all the lines that will not compile------//
//------in the main function of the following program------//
//----------------Do NOT run on Compiler--------------------//
#include <iostream>
using namespace std;
class A
{
public:
    A() {}
    virtual int output() = 0;

private:
    int i;
};

class B : public A
{
private:
    int j;
};

class C
{
public:
    int f(int a) { return x * a; }

protected:
    void setX(int a) { x = a; }
    int getX() { return x; }

private:
    int x;
};

class D : public C
{
private:
    int z;
};

int main()
{
    //A objA;  ~
    //B objB;  ~
    C objC;  
    D objD;
    //C.setX(2); ~
    //cout << C.getX();~
    //D.setX(1);~
    //D.f(3);~
    return 0;
}
/*
2

*/