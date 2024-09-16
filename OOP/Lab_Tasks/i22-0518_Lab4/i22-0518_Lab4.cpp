//============================================================================
// Name        : oop.cpp
// Author      : umer farooq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Factorial(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return n* Factorial(n-1);
	}
}
int fibonacci(int x)
{
	if(x==0|| x==1)
	{
		return x;
	}
	else
	{
		 return (fibonacci(x-1)+fibonacci(x-2));

	}
}
int findGCD(int num1,int num2)
{
	if(num2==0)
	{
		return num1;
	}
	else
	{
		return findGCD(num2,num1%num2);
	}
}
bool elfish(char word[], char elf[], int index)
{
	if(word[index]==elf[0])
	{
		if(word[index]== elf[1])
			if(word[index]== elf[2])
				return true;
	}

	else
	{
		return elfish(word,elf,index+1);
	}
}
bool LinearSearch(int array[10],int find, int size)
{
	if(size>=0)
	{
		if(array[size] == find)
		{
			return true;
		}

		else
		{
			LinearSearch(array,find,size-1);
		}
	}
	else
	{
		return false;
	}
}
//int main()
//{
////	problem 1
////	int num=5;
////	cout<< Factorial(num);
////
////	problem 2
////	int n;
////	cout<<"Enter number of terms"<<endl;
////	cin>>n;
////	for(int i=0;i<n;i++)
////	{
////		cout<<fib(i)<<" ";
////	}
////	problem 3
////	int n1=10,n2=15;
////	cout<<findGCD(10,15)<<endl;
////
////	problem 4
////	char word[10]="leaf";
////	char elf[4]= "elf";
////	for(int i=0;i<10;i++)
////	{
////		cout<<elfish(word, elf, i);
////	}
//
////	problem 5
//	int arr[10]={1,2,3,4,5,6,7,8,9,10};
//	int size =10;
//	int find=2;
//	cout<<LinearSearch(arr,find, --size)<<endl;
//}




