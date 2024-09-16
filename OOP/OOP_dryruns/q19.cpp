#include <iostream>
using namespace std;
class XYZ
{
private:
    int x;
public:
    XYZ(int y = 10)
    {
        x = y;
        cout << "XYZ() called for " << x << endl;
    }
    void Print()
    {
        cout << x << endl;
    }
    ~XYZ()
    {
        cout << "~XYZ() Called.\n";
    }
};

class ABC
{
    int c;

public:
    XYZ a;
    XYZ *b;
    ABC(int val = 50)
    {
        c = val;
        cout << "ABC() called for " << c << endl;
        b = new XYZ(a);
    }
    void Print()
    {
        cout << "c = " << c << endl;
        cout << "a = ";
        a.Print();
        if (b != nullptr)
        {
            cout << "b =  ";

            b->Print();
        }
    }
};

int main()
{
    ABC *x = new ABC;
    x->Print();
    XYZ *ptr = &(x->a);
    delete x;
    ptr->Print();
}