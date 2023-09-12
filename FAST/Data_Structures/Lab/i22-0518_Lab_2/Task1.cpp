#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 5;
    int l = 1;
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            for (int c = 1; c <= n; c++)
            {
                int a3 = pow(a, 3);
                int b3 = pow(b, 3);
                int c3 = pow(c, 3);
                int d = cbrt(a3 + b3 - c3);
                int d3 = pow(d, 3);
                if (a3 + b3 == c3 + d3)
                {
                    cout << "LINE NUMBER : " << l++ << ">> " << a << " " << b << " " << c << " " << d << " " << endl;
                }
            }
        }
    }
}