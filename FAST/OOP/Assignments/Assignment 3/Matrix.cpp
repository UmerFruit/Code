/*
 * Matrix.cpp
 *
 *  Created on: 25-Mar-2023
 *      Author: umerfarooq
 */

#include "Matrix.h"

int Matrix::counter = 0; // initializing the static int

Matrix::Matrix()
{
	counter++;
	cout << "Enter number of rows for Matrix " << counter << " : ";
	cin >> rows;
	cout << "Enter number of columns for Matrix " << counter << " : ";
	cin >> columns; // take input from user for rows and coloumns
	mat = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[columns]; // allocated the memory
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] = 0;
		}
	}
}
Matrix::Matrix(int r, int c)
{
	counter++;
	rows = r;
	columns = c;
	mat = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[columns]; // allocated the memory
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] = 0;
		}
	}
}
void Matrix::display()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << mat[i][j] << " "; // display
		}
		cout << endl;
	}
}
Matrix::Matrix(Matrix &m)
{
	rows = m.rows;
	columns = m.columns;
	mat = new int *[rows];
	for (int i = 0; i < rows; i++)
	{
		mat[i] = new int[columns]; // copy constructor
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->mat[i][j] = m.mat[i][j];
		}
	}
}

void Matrix::setMat()
{
	cout << "Enter values of the Matrix : " << endl;
	char nums[100];
	cin >> nums;
	char temp[100]; // take input as string and convert to ints
	int i = 0;
	while (nums[i] != '\0')
	{
		temp[i] = nums[i];
		i++;
	}
	temp[i] = '\0';
	char *n = strtok(temp, ",");
	int numval = 0;
	while (n != NULL)
	{
		n = strtok(nullptr, ",");
		numval++;
	}
	if (numval > (rows * columns))
	{
		cout << "Too Many values" << endl; // input validation
		return;
	}
	else if (numval < (rows * columns))
	{
		cout << "Too Few values" << endl; // input validation
		return;
	}
	n = strtok(nums, ",");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			mat[i][j] = stoi(n); // convert to int and store  in matrix
			n = strtok(nullptr, ",");
		}
	}
}
int Matrix::getColumns() const { return columns; }
int **Matrix::getMat() const { return mat; } // getter
int Matrix::getRows() const { return rows; }

Matrix &Matrix::operator+(Matrix &m)
{
	if ((rows == m.rows) && (columns == m.columns))
	{
		Matrix *temp = new Matrix(rows, columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				(*temp).mat[i][j] = this->mat[i][j] + m.mat[i][j]; // store in temp and return that obj
			}
		}
		return *temp;
	}
	else
	{
		cout << "Invalid Operation" << endl;
		exit(0);
	}
}
Matrix &Matrix::operator-(Matrix &m)
{
	if ((rows == m.rows) && (columns == m.columns))
	{
		Matrix *temp = new Matrix(rows, columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				(*temp).mat[i][j] = this->mat[i][j] - m.mat[i][j]; // store in temp and return that obj
			}
		}
		return *temp;
	}
	else
	{
		cout << "Invalid Operation" << endl;
		exit(0);
	}
}
Matrix &Matrix::operator*(Matrix &m)
{
	if (columns == m.rows)
	{
		Matrix *temp = new Matrix(this->rows, m.columns);
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < m.columns; j++)
			{
				temp->mat[i][j] = 0;
				for (int k = 0; k < m.rows; k++) // inner loop to traverse the * of columns with rows
				{
					temp->mat[i][j] += mat[i][k] * m.mat[k][j]; // store in temp and return that obj
				}
			}
		}
		return *temp;
	}
	else
	{
		cout << "Invalid Operation" << endl;
		exit(0);
	}
}
Matrix &Matrix::operator*(int n)
{
	Matrix *temp = new Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++) // multiply each element
		{
			temp->mat[i][j] = this->mat[i][j] * n; // store in temp and return that obj
		}
	}
	return *temp;
}
Matrix &Matrix::operator=(Matrix &m)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mat[i]; // deep copies elements from the arrays
	}
	delete[] mat;

	rows = m.rows;
	columns = m.columns;
	mat = new int *[rows];
	for (int i = 0; i < rows; i++) // works just like copy constructor
	{
		mat[i] = new int[columns];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->mat[i][j] = m.mat[i][j];
		}
	}
	return *this;
}
bool Matrix::operator==(Matrix &m)
{
	if ((rows == m.rows) && (columns == m.columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (mat[i][j] != m.mat[i][j])
				{
					return false; // checks if all elements are equal and size is equal
				}
			}
		}
		return true;
	}
	else
		return false;
}
Matrix &Matrix::operator++()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			this->mat[i][j]++; // pre fix increment operator
		}
	}
	return *this;
}
Matrix& Matrix::operator++(int)
{
	Matrix *temp = new Matrix(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp->mat[i][j] = this->mat[i][j]++; // post fix increment operator
		}
	}
	return *temp;
}
ostream &operator<<(ostream &os, Matrix &right)
{
	right.display(); // display using ostream object
	return os;		 // operator overloading for cout
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}
