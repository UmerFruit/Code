//---------------------Question # 7---------------------//
#include <iostream>
using namespace std;
class Parent
{
    int *b;

public:
    Parent() { b = new int(10); }
    virtual void Print()
    {
        cout << "B = " << *b << endl;
    }
    ~Parent() { delete b; }
};

class Child : public Parent
{
    int *d;

public:
    Child() { d = new int(20); }
    void Print()
    {
        Parent::Print();
        cout << "D = " << *d << endl;
    }
    ~Child() { delete d; }
};

int main()
{
    Parent *pPtr = new Child();
    pPtr->Print();
    delete pPtr;
}
/*
B = 10
D = 20

*/