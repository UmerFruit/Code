#include "Headers.h"
using namespace std;
int main()
{
    srand(time(0));
    int num2 = rand()%1000000;
    int num1 = rand()%1000000;
    cout<<"REAL answer is :"<<num1-num2<<endl;
    int num2com = 999999 - num2;
    int sum = num1 + num2com;
    int c = 0;
    cout<<sum<<endl;
    int rem = sum/1000000;
    cout<<"sum: "<<sum<<endl;
    cout<<"rem: "<<rem<<endl;
    int mod = sum%1000000;
    int ans = ((999999*(!rem) - sum-(rem))%1000000)*(-1);
    cout<<"ans: "<<ans<<endl;
}
