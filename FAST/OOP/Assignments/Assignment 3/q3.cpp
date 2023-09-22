#include "Fraction.cpp"
int main()
{
    Fraction f1(1, 2), f2(1, 2);
    f1.display();
    f2.display();
    Fraction f3 = f1 + f2;
    f3.display();
    f3 = f1 - f2;
    f3.display();
    f3 = f1 * f2;
    f3.display();
    f3 = f1 / f2;

    f3.display();

    // f3.display();
    return 0;
}