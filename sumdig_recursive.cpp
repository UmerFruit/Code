#include "Headers.h"
using namespace std;
int sumdig(int x)
{
    if(x/10 == 0)
    {
        return x;
    }
    int sum = sumdig(x/10) + sumdig(x%10);
    return sum;
}
int main()
{
   cout<<sumdig(354)<<endl;
   
}
