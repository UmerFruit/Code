#include<iostream>
#include<cstring>
using namespace std;
void shift_Circular(int p[],int size);
int main()
{   
    const int SIZE=5;
    int p[SIZE]={28,19,61,15,30};
    cout<<"Enter values for array"<<endl;
    for(int i=0;i<SIZE;i++)
    {
       cin>>p[i];
    }
    shift_Circular(p,SIZE);
}
void shift_Circular(int p[],int size)
{   
    int temp=p[0];
    for(int i=2;i<5;i += 2)
    {   
        int temp=p[i];
        p[i]=p[i-2];
        p[i-2]=temp;
    }
    for(int i=1;i<4;i += 2)
    {
        if(i==1)
        {
            int temp=p[i];
            p[i]=p[5+(i-2)];
            p[5+(i-2)]=temp;
        }
        else
        {
            int temp=p[i];
            p[i]=p[i-2];
            p[i-2]=temp;
        }
    }
    p[3]=temp;
    cout<<"The array is now : "<<endl;
    for(int i=0;i<5;i ++)
    {
        cout<<p[i]<<" ";
    }
}
