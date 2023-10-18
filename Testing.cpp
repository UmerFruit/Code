#include "Headers.h"
using namespace std;
class Int
{
    int a;

public:
    Int()
    {
        a = 5;
    }
    void display()
    {
        cout << a << endl;
    }
    Int(int a)
    {
        this->a = a;
    }
    int operator+(Int m)
    {
        return this->a + m.a;
    }
};
void part1(string name)
{
    char c;
    for (int j = 0; j < name.length(); j++)
    {
        for (int i = 0; i < 26; i++)
        {
            c = 'a' + i;
            usleep(30000);
            cout << c << flush << "\b";
        }

        for (int i = 0; i < 26; i++)
        {
            c = 'a' + i;
            usleep(30000);
            cout << c << flush;
            if (c != name[j])
            {
                cout << '\b';
            }
            else
                break;
        }
    }
}
int main()
{
    part1("hassaansiddiqui");
    cout<<endl;
}
