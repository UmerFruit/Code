//---------------------Question # 3---------------------//
#include <iostream>
using namespace std;
class D
{
public:
    D() { cout << "D ctor" << endl; }
    D(D &) { cout << "D copy ctor" << endl; }
    
    ~D() { cout << "D dtor" << endl; }
};
class A
{
public:
    A() { cout << "A ctor" << endl; }
    ~A() { cout << "A dtor" << endl; }
};
class B : public A
{
public:
    B() { cout << "B ctor" << endl; }
    ~B() { cout << "B dtor" << endl; }
    void test(D d) { A a; }
};
B globalB;

int main()
{
    A a;
    D d;
    D d2 = d;
    d = d2;
    globalB.test(d);
    return 0;
}
/*
A ctor
B ctor
A ctor
D ctor
D copy ctor
D copy ctor
A ctor
A dtor
D dtor
D dtor
D dtor
A dtor
B dtor
A dtor
*/