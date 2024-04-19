#include<iostream>
using namespace std;

bool perfect(int num)
{
    
    int sum=0;
    for(int i=1;i<=num;i++)
    {
        if(num%i==0)
        {
            if(i==num)
            {continue;}
            else
            {
                sum+=i;
            }
        }
        
    }
       return sum==num;
}


int main(){
    
    bool check;
    cout<<"For the integers from 1 - 1000 : "<<endl;
        for(int num=1;num<=1000;num++)
        {
        
        check=perfect(num);
        if(check == 1)
        {
            cout<<num<<" is a perfect number"<<endl;
        }
        }
        
}
       
