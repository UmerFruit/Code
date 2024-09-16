//---------------------Question # 12---------------------//
#include <iostream>
using namespace std;
class A
{
private:
    int *aptr;

public:
    A(int a = 5)
    {
        aptr = new int(a);
    }
    virtual void Print()
    {
        cout << "a = " << *aptr << endl;
    }
    virtual ~A()
    {
        cout << "~A() called.\n";
        if (aptr != 0)
            delete aptr;
    }
};

class B : public A
{
private:
    int *bptr;

public:
    B(int b = 10)
    {
        bptr = new int(b);
    }
    void Print()
    {
        A::Print();
        cout << " b = " << *bptr << endl;
    }
    ~B()
    {
        cout << "~B() called.\n";
        if (bptr != 0)
            delete bptr;
    }
};

class C : public A
{
private:
    int *cptr;

public:
    C(int c = 15) : A(c * 10)
    {
        cptr = new int(c);
    }
    void Print()
    {
        A::Print();
        cout << " c = " << *cptr << endl;
    }
    ~C()
    {
        cout << "~C() called.\n";
        if (cptr != 0)
            delete cptr;
    }
};

int main()
{
    A *aptr[3];
    aptr[0] = new B(1);
    aptr[1] = new C(2);
    aptr[2] = new A(3);

    for (int i = 0; i < 3; i++)
        aptr[i]->Print();

    for (int i = 0; i < 3; i++)
        delete aptr[i];
}
/*
    A::aptr 5
    B::bptr 1

    aptr 5
    bptr 10
    cptr 2

    aptr 3

    a=5
    b=1

    a=20
    c=2

    a=3
    ~B() called.
    ~A() called.
    ~C() called.
    ~A() called.
    ~A() called.

*/