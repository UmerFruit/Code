//----------Question---------//
#include <iostream>
using namespace std;
class Complex
{
    double r, i;

public:
    Complex(double r = 1.0, double i = 1.0)
    {
        set(r, i);
    }

    void set(double r, double i)
    {
        Complex::r = r; //this hona chahiye?
        this->i = i;
    }

    void print()
    {
        if(i < 0)
            cout<<r<<""<<i<<"i"<<endl;
        else
            cout<<r<<"+"<<i<<"i"<<endl;
    }

    Complex operator+(Complex R)
    {
        Complex tmp;
        tmp.r = r + R.r;
        tmp.i = i + R.i;
        return tmp;
    }

    Complex operator++()
    {
        Complex tmp = *this;
        r++;
        i++;
        return tmp;
    }

    Complex operator++(int)
    {
        ++(*this); //ulti implementation but valid
        return *this;
    }
};

int main()
{
    Complex A(3, 4), B(5, -6);
    A.print();
    B.print();
    Complex C;
    C = A + B;
    C.print();
    (++A).print();
    C = ++A;
    C.print();
    (A++).print();
    A.print();
    return 0;
}