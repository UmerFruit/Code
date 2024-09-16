#include <iostream>
using namespace std;
void reverse(int &num);
int main()
{   int n;
    cout<<"Enter any number "<<endl;
    cin>>n;
    if(n>=0)
    {
    reverse(n);
    cout<<"Reversed number : "<<n<<endl;
    }
    else
    {
        cout<<"Enter positive value only"<<endl;
    }
}
void reverse(int &num)
{   int rem;
    int temp=num,numdig,sum=0;
    for(numdig=0;temp>0;numdig++)
    {
        temp=temp/10;
    }
    temp=num;
    for(int i=1;i<=numdig;i++)
    {   
        rem= temp%10;
        sum = sum*10 + rem;
        temp /= 10; 
    }
    num=sum;
}