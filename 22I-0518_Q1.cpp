#include<iostream>
#include <cmath>
using namespace std;

int B2D(long long num);
long long D2B(long long num);

int main(){
    
    long long number,temp;
    bool isD=false;
    int numdigits=0;
    int Dnum;
    long long Bnum;
    cout<<"Please Enter a number for conversion:\n";
    cin>>number;
    
    temp= number;
    
    while(temp!=0)
    {
       temp /= 10;
       numdigits++;
    }
    temp=number;
    for(int i=0;i<numdigits;i++)
    {
        if(temp%10!= 0 && temp%10!= 1)
        {
            isD= true;
            break;
        }
        temp= temp/10;
    }
    if(isD)
    {
      Bnum = D2B(number); 
      return Bnum;
    }
    else
    {
        Dnum = B2D(number);
        return Dnum;
    }
    
}
int B2D(long long num)
{
    int sum=0;
    long long temp=num;
    for(int i=0;temp!=0;i++)
    {
        sum += ((temp%10) * pow(2,i));
        temp = temp/10;
    }
    return sum;
}
long long D2B(long long num)
{
    long long sum=0,temp=num;
    long long Bnum=0;
    int i=0;
    while(pow(2,i)<num)
    {
        
        i++;
    }
    
    while(i!=-1)
    {
        sum= sum+pow(2,i);
        if(sum>num)
        {
            sum= sum-pow(2,i);
        }
        else
        {
            Bnum += pow(10,i);
        }
        i--;
    }
    
    return Bnum;
}
