//============================================================================
// Name        : Lab2.cpp
// Author      : Umer Farooq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void getAddress(int &num)
{
	int* ptr= &num;
	cout<<ptr<<endl<<*ptr;
	*ptr= 5; //changes value to 5
	cout<<endl<<*ptr;
}

void swap(int* n1,int* n2)
{
	int temp=*n1;
	*n1=*n2;
	*n2=temp;
	cout<<*n1<<endl<<*n2;
}

int* duplicate(int *ptr2,int arr2[],int length)
{
	cout<<"Enter numbers"<<endl;
	for(int i=0;i<length;i++)
	{
		cin>>*(ptr2+i);
	}
	cout<<"first array"<<endl;
	for(int i=0;i<length;i++)
	{
		cout<<*(ptr2+i)<<endl;
	}
	for(int i=0;i<length;i++)
	{
		*(arr2+i) = *(ptr2+i);
	}
	cout<<"second array"<<endl;
	for(int i=0;i<length;i++)
		{
			cout<<*(arr2+i)<<endl;
		}
	return arr2;
}

int countPrime(int arr[],int size,int count)
{


	for(int i=0;i<size;i++)
	{
		int c=0;
		for(int j=1;j<*(arr+i)/2;j++)
		{
			if((*(arr+i))%j==0)
			{
				c++;
			}

		}
		if(c>1)
		{
			count++;
		}
	}

	cout<<"Number of primes are "<<count;
	return count;
}

char* toCapital(char* p)
{
	int size=0,i=0;
	while(*(p+i) != '/0')
	{
		size++;
	}
	for(int i=0;i<size;i++)
	{
		*(p+i)= *(p+i)-32;
		cout<<*(p+i);
	}

	return p;

}

int main() {
	int x=75;
	//getAddress(x);
	//address
	int a=6,b=3;
	//swap(&a,&b);
	//swap
	 int *arr1=new int[10];
	    //int arr[10];
	    for (int i = 0; i < 10; i++) arr1[i]=i*2+11;
	    int *ptr=arr1;
	    //duplicate(ptr,arr,10);

	//duplicate
	    int arr[]={9,23,22,7,9,11};
	       int size=6, count=3;
	       //countPrime(arr,size,count);
	//prime
	       char str[14]="cybersecurity";
	         char *p=str;
	         char *expec=toCapital(p);
	         cout<<*expec;
	//capital

	return 0;
}
