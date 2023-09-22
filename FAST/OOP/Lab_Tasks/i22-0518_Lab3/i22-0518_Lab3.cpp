//============================================================================
// Name        : oop.cpp
// Author      : umer farooq
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int* CalculateSum(int** p1,int m, int n)
{

	int* sumarr = new int[m];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			*(sumarr+i)+=*(*(p1+i)+j);
		}
	}
	return sumarr;
}

string diagonal(int** matrix,int rows,int columns)
{
	int check=1;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(*(*(matrix+i)+j)!=0)
			{
				check=0;
				break;
			}
		}
	}
	if(check==1)
	{
		return "upper";
	}
	else
	{
		return "notupper";
	}

}
int** MatrixSum(int** MatrixA, int** MatrixB,int nrows,int ncols)
{
	int **MatrixC=new int*[nrows];
	for (int i=0;i<4;i++)
	{
	   *(MatrixC+i)=new int [ncols];
	}
	for(int i=0;i<nrows;i++)
	{
		for(int j=0;j<ncols;j++)
		{
			*(*(MatrixC+i)+j) = *(*(MatrixA+i)+j) + *(*(MatrixB+i)+j);
		}
	}
	return MatrixC;
}
void ThreeD (int*** ptr, int pages, int rows, int columns)
{
	ptr=new int**[pages];
		for (int i=0;i<pages;i++)
		{
		   *(ptr+i)=new int* [rows];
		   for(int j=0;j<rows;j++)
		   {
			   *(*(ptr+i)+j)=new int [columns];
		   }
		}
}
int*** Square(int*** sqr, int pages, int rows, int columns)
{
	for(int i=0;i<pages;i++)
	{
		for(int j=0;j<rows;j++)
		{
			for(int k=0;k<columns;k++)
			{
				*(*(*(sqr+i)+j)+k)= (*(*(*(sqr+i)+j)+k)) * (*(*(*(sqr+i)+j)+k));
			}
		}
	}
	return sqr;
}
/*
int main()
{
	//problem 5
	/*
	int pages=5,rows=6,columns=3;
	int*** sqr=new int**[pages];
	for (int i=0;i<pages;i++)
	{
	  *(sqr+i)=new int* [rows];
	   for(int j=0;j<rows;j++)
	   {
		   *(*(sqr+i)+j)=new int [columns];
	   }
	}

	for(int i=0;i<pages;i++)
	{
		for(int j=0;j<rows;j++)
		{
			for(int k=0;k<columns;k++)
			{
				*(*(*(sqr+i)+j)+k)= k;
			}
		}
	}
	int*** lol = Square(sqr,pages, rows, columns);
	for(int i=0;i<pages;i++)
	{
		for(int j=0;j<rows;j++)
		{
			for(int k=0;k<columns;k++)
			{
				cout<<*(*(*(lol+i)+j)+k);
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
*/



