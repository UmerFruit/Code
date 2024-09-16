//============================================================================
// Name        : oop.cpp
// Author      : umer farooq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int pow(int b,int e)
{
	if(e==0)
	{
		return 1;
	}
	else if(e==1)
	{
		return b;
	}
	else
	{
		return b*(pow(b,e-1));
	}
}

void PrintScreen5(char ch,int lines, int start)
{
	if(start==lines)
			{
				return;
			}
			else
			{
				PrintScreen5(ch,lines,start+1);
				cout<<ch;
			}
}
void patterncall(char ch,int lines, int start)
{
	if(start>lines)
		{
			return;
		}
		else
		{
			PrintScreen5(' ',lines,start);
			PrintScreen5(ch,lines,lines-start);
			cout<<endl;
			patterncall(ch,lines,start+1);

			PrintScreen5(' ',lines,start);
			PrintScreen5(ch,lines,lines-start);
			cout<<endl;
		}
}
int product(int a, int b)
{
	if(b==0)
	{
		return 0;
	}
	else
	{
		return a+product(a,b-1);
	}
}

void pat2(int rows,int inc,int vals)
{

	if(rows<vals)
	{
		return;
	}
	else
	{

		pat2(rows,inc+1,vals+1);
		cout<<static_cast<char> ( 64+inc)<<"\t";
	}
}
void Pattern2(int rows,int inc,int vals)
{
	if(rows<vals)
	{
		return;
	}
	else
	{

		Pattern2(rows,inc,vals+1);
		pat2(rows,inc,vals);
		cout<<endl;
	}
}
bool Sub(char str1[], char str2[], int length1, int length2)
{
	if(length2==0)
	{
		return true;
	}
	else
	{
		if(*(str1+length1) == *(str2+length2))
		{
			return sub(str1,str2,length1+1,length2+1)
		}
		else
		{
			return false;
		}
	}
}
bool SubString(char str1[], char str2[], int length1, int length2)
{
	if(length1 == 0)
	{
		return false;
	}
	else
	{
		return true;
		SubString(str1,str2,length1-1,length2);
		if(*(str1+length1) == *(str2+length1))
		{
			sub(str1,str2,length1,length2);
		}
	}

}

//int main()
//{
////	//problem 1
////	int b=2,e=5;
////	cout<<pow(b,e);
////	//problem2
////	patterncall('-',5,1);
//	//problem 3
////	cout<<product(2,20);
//	//problem  4
//	//Pattern2(6,1,1); //incomplete
//	//problem 5
//	//SubString(str1,str12,length1,length2)
//
//}




