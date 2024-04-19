/*
 * Matrix.h
 *
 *  Created on: 25-Mar-2023
 *      Author: umerfarooq
 */

#ifndef MATRIX_H_
#define MATRIX_H_
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Matrix
{
private:
	int rows;
	int columns;
	int **mat;
	static int counter;

public:
	// constructors
	Matrix();
	Matrix(int, int);
	Matrix(Matrix &);
	~Matrix();
	// utility & setters and getters
	void display();
	int getColumns() const;
	void setMat();
	int **getMat() const;
	int getRows() const;
	// operator overloads
	Matrix &operator+(Matrix &);
	Matrix &operator-(Matrix &);
	Matrix &operator*(Matrix &);
	Matrix &operator*(int);
	Matrix &operator=(Matrix &);
	bool operator==(Matrix &);
	Matrix &operator++();
	Matrix &operator++(int);
	friend ostream &operator<<(ostream &os, Matrix &right);
};

#endif /* MATRIX_H_ */
