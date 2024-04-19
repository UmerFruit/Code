//-----------Question----------//
#include <iostream>
using namespace std;
class Mystery
{
public:
    static int n;

    Mystery()
    {
        cout<<n++<<endl;
    }
    Mystery(int i)
    {
        n = i;
        cout<<n<<endl;
    }
    static void somefunc()
    {
        n = 5;
    }

    Mystery(Mystery const& otherNum)
    {
        n += 5;
        cout<<n<<endl;
    }

    ~Mystery()
    {
        cout<<--n<<"\n";
    }
}a;

void fun(Mystery n)
{
    cout<<n.n<<endl;
    n.somefunc();
}

int Mystery::n = 0;

int main()
{
    Mystery b(9), c;
    fun(b);
    return 0;
}
/*
 * 0
 * 9
 * 9 //real 10
 * 10 //real 5
 * 
 * 
 * 
 */
