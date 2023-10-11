#include "Headers.h"
int main()
{
    int a1 = rand() % 10;
    int b1 = rand() % 10;
    int c1 = rand() % 10;
    int a2, b2, c2;
    cout << "a1 = " << a1 << endl;
    cout << "b1 = " << b1 << endl;
    cout << "c1 = " << c1 << endl;

    cout << "Enter 3 numbers: " << endl;
    cin >> a2 >> b2 >> c2;
    bool condp1 = (a1 == a2 || a1 == b2 || a1 == c2) && (b1 == a2 || b1 == b2 || b1 == c2);
    bool condp2 = (b1 == a2 || b1 == b2 || b1 == c2) && (c1 == a2 || c1 == b2 || c1 == c2);
    bool condp3 = (a1 == a2 || a1 == b2 || a1 == c2) && (c1 == a2 || c1 == b2 || c1 == c2);

    bool cond1 = (a1 == a2 || a1 == b2 || a1 == c2);
    bool cond2 = (b1 == a2 || b1 == b2 || b1 == c2);
    bool cond3 = (c1 == a2 || c1 == b2 || c1 == c2);

    if (a1 == a2 && b1 == b2 && c1 == c2)
    {
        cout << "3 matched in order" << endl;
    }
     else if (cond1 && cond2 && cond3)
    {
        cout << "3 matched but not in order" << endl;
    }
    else if (condp1 || condp2 || condp3)
    {
        cout << "Any two matched" << endl;
    }
    else if (cond1 || cond2 || cond3)
    {
        cout << "Any one matched" << endl;
    }
    else
    {
        cout << "nothing matched! :(" << endl;
    }
}
