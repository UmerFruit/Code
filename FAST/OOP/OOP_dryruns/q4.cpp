//---------------------Question # 4---------------------//
#include <iostream>
using namespace std;
class A
{
public:
    A() { cout << "In As constructor" << endl; }
    ~A() { cout << "In As destructor" << endl; }
};


class B : public A
{
public:
    B() { cout << "In Bs constructor" << endl; }
    ~B() { cout << "In Bs destructor" << endl; }
};

class C : public B
{
public:
    C() { cout << "In Cs constructor"<< endl; }
    ~C() { cout << "In Cs destructor"<< endl; }
};


int main()
{
    C x1;
    C *x2 = new C;
}
/*
In As constructor
In Bs constructor
In Cs constructor
In As constructor
In Bs constructor
In Cs constructor
In Cs destructor
In Bs destructor
In As destructor
*/