#include "Headers.h"
int main()
{
    int num, req;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                num = i * 300 + j * 30 + k * 3;
                req = j * 111;
                if (num == req)
                {
                    cout << i * 100 + j * 10 + k << " is a possible solution." << endl;
                }
            }
        }
    }
}