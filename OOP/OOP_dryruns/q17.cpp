#include<iostream>
using namespace std;

class A
{
private:
	int a;
public:
	A(int x = 10) { a = x; cout << "A() called for "<<a<<" .\n"; }
	~A() {	cout << "~A() called for a = " << a << endl;	}
	void Print() { cout << "a = " << a << endl; }
};
class B
{
private:
	int b;
	A a;
	A* aptr;
public:
	B(){ b = 0; aptr = 0; cout << "B() called." << endl; }
	B(int x, A* objPtr) :a(x+5)
	{
		b = x;
		aptr = objPtr;
		cout << "B() called for b = "<< b << endl;
	}
	void Print() { cout << "b = " << b<<endl; a.Print();
		if(aptr != 0) aptr->Print();
	}
	~B(){ cout << "~B() called for b = " << b << endl; }
};
int main()
{
	A a1(5);
	B b1(10, &a1);
	cout<<"---------------------------\n";
	b1.Print();
}
/*
A() called for 5.
A() called for 15.
B() called for b = 10.
---------------------------
b = 10
a = 15
a = 5
~A() called for a = 15
~B() called for b = 10
~A() called for a = 5
*/