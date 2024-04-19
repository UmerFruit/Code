/*
 * Matrix.h
 *
 *  Created on: Mar 22, 2023
 *      Author: umer
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
using namespace std;
class Matrix
{
private:
	int rows;
	int coloumns;
	int** matrix;
public:
	Matrix(int,int);
	bool operator == (Matrix&);
	const Matrix operator = (Matrix&);
	Matrix operator + (Matrix&);
	Matrix operator - (Matrix&);
	Matrix operator + (int);
	Matrix operator - (int);
	void print();

};
void Matrix::print()
{
	for(int i=0;i<rows;i++)
		{
			for(int j=0;j<coloumns;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
}
Matrix::Matrix(int r,int c)
{
	rows = r;
	coloumns = c;
	matrix = new int*[r];
	for(int i=0;i<r;i++)
	{
		matrix[i] = new int [c];
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<coloumns;j++)
		{
			matrix[i][j] = 2;
		}
	}

}
bool Matrix::operator == (Matrix& obj)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<coloumns;j++)
		{
			if(matrix[i][j] != obj.matrix[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
const Matrix Matrix::operator = (Matrix& obj)
{
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<coloumns;j++)
		{
			this->matrix[i][j] = obj.matrix[i][j];
		}
	}
	return *this;

}
Matrix Matrix::operator + (Matrix& obj)
{
	if((rows == obj.rows) && (coloumns == obj.coloumns))
	{
		Matrix temp(rows,coloumns);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<coloumns;j++)
			{
				temp.matrix[i][j] = matrix[i][j] + obj.matrix[i][j];
			}
		}
		return temp;
	}
	return *this;
}
Matrix Matrix::operator - (Matrix& obj)
{
	if((rows == obj.rows) && (coloumns == obj.coloumns))
	{
		Matrix temp(rows,coloumns);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<coloumns;j++)
			{
				temp.matrix[i][j] = matrix[i][j] - obj.matrix[i][j];
			}
		}
		return temp;
	}

	return *this;
}
Matrix Matrix::operator + (int l)
{
	Matrix temp(rows,coloumns);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<coloumns;j++)
			{
				temp.matrix[i][j] = matrix[i][j] + l;
			}
		}
		return temp;
}
Matrix Matrix::operator - (int l)
{
	Matrix temp(rows,coloumns);
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<coloumns;j++)
			{
				temp.matrix[i][j] = matrix[i][j] - l;
			}
		}
		return temp;
}
#endif /* MATRIX_H_ */
