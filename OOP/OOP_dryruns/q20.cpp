#include <iostream>
using namespace std;

class Rectangle
{
private:
    int *lenght;
    int *width;

public:
    Rectangle(int l = 0, int w = 0);
    Rectangle(const Rectangle &);
    ~Rectangle();
    void Print();
    const Rectangle &operator=(const Rectangle &);

    Rectangle GetRotatedRect()
    {
        cout << "-----------------" << endl;
        Rectangle temp;
        *temp.lenght = *width;
        *temp.width = *lenght;
        cout << "#################" << endl;
        return temp;
    }
};
Rectangle::Rectangle(int l, int w)
{
    cout << "Constructor Called for " << l << " X " << w << ".\n\n";
    lenght = new int(l);
    width = new int(w);
}
Rectangle::Rectangle(const Rectangle &rhs)
{
    cout << "Copy Constructor Called to create a copy of Rectangle " << *rhs.lenght << " X " << *rhs.width << endl;
    lenght = new int(*rhs.lenght);
    width = new int(*rhs.width);
}

Rectangle::~Rectangle()
{
    cout << "Destructor Called for rectangle " << *lenght << " X " << *width << "\n\n";
    delete lenght;
    delete width;
}
const Rectangle &Rectangle::operator=(const Rectangle &rhs)
{
    cout << "Overloaded Assignment Operator Called for LHS " << *rhs.lenght << " X " << *rhs.width << endl;

    if (&rhs != this)
    {
        *lenght = *rhs.lenght;
        *width = *rhs.width;
    }
    return *this;
}

void Rectangle::Print()
{
    cout << *lenght << " X " << *width << endl
         << endl;
}

int main()
{
    Rectangle r1(2, 3);
    Rectangle r2;

    r2 = r1.GetRotatedRect();
    cout << "r2:\t";
    r2.Print();
}
/*
Constructor Called for 2 X 3. 

Constructor Called for 0 X 0. 

-----------------
Constructor Called for 0 X 0. 

Overloaded Assignment Operator Called for LHS 2 X 3
Destructor Called for rectangle 3 X 2.

r2:     3 X 2

Destructor Called for rectangle 3 X 2

Destructor Called for rectangle 2 X 3
*/