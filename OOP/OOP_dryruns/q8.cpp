//---------------------Question # 8---------------------//
#include <iostream>
using namespace std;
class B
{
private:
    int *bptr;

public:
    B(int b = 10) { bptr = new int(b); }
    virtual int GetValue()
    {
        return *bptr;
    }
    virtual ~B()
    {
        cout << "~B()";
        if (bptr != 0)
            delete bptr;
    }
};

class D1 : public B
{
private:
    int *dptr1;

public:
    D1(int d1 = 20) { dptr1 = new int(d1); }
    int GetValue()
    {
        return (B::GetValue() + *dptr1);
    }
    void Print()
    {
        cout << "*dptr1 = " << *dptr1 << endl;
    }
    ~D1()
    {
        cout << "~D1()";
        if (dptr1 != 0)
            delete dptr1;
    }
};

class D2 : public B
{
private:
    int *dptr2;

public:
    D2(int d2 = 30)
    {
        dptr2 = new int(d2);
    }
    int GetValue()
    {
        return (B::GetValue() + *dptr2);
    }
    ~D2()
    {
        cout << "~D2()";
        if (dptr2 != 0)
            delete dptr2;
    }
};

class GC : public D1
{
private:
    int *gcPtr;

public:
    GC(int gc = 40) : D1(gc + 10)
    {
        gcPtr = new int(gc);
    }
    int GetValue()
    {
        return (D1::GetValue() + *gcPtr);
    }
    void Print()
    {
        cout << "*gcptr = " << *gcPtr << endl;
    }
    ~GC()
    {
        cout << "~GC()";

        if (gcPtr != 0)
            delete gcPtr;
    }
};
int main()
{
    B *arr[4];
    arr[0] = new B(1);
    arr[1] = new D1(2);
    arr[2] = new D2(3);
    arr[3] = new GC(4);

    for (int i = 0; i < 4; i++)
    {
        cout << arr[i]->GetValue() << " , ";
    }

    cout << endl;

    for (int i = 0; i < 4; i++)
    {
        delete arr[i];
        cout << endl;
    }

    cout << "-------------------------\n";

    D1 *arr2[2];
    arr2[0] = new D1(100);
    arr2[1] = new GC(500);

    for (int i = 0; i < 2; i++)
        arr2[i]->Print();

    for (int i = 0; i < 2; i++)
    {
        delete arr2[i];
        cout << endl;
    }
}
/*
bptr = 1

bptr1 = 10
d1ptr = 2

bptr1 = 10
dptr2 = 3

bptr = 10
d1ptr = 14
gcPtr = 4

d1ptr = 100
bptr = 10

bptr = 10
d1ptr = 510
gcptr = 500



1 , 12 , 13 , 28
~B()
~D1()~B()
~D2()~B()
~GC()~D1()~B()
-------------------------
*d1ptr = 100
*gcptr = 500
~D1()~B()
~GC()~D1()~B()
*/