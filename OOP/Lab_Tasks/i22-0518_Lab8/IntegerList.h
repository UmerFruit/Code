/*
 * IntegerList.h
 *
 *  Created on: Mar 15, 2023
 *      Author: umer
 */

#ifndef INTEGERLIST_H_
#define INTEGERLIST_H_
#include <cstdlib>
#include <iostream>
using namespace std;
class IntegerList
{
private:
	int size;
	int *list;
	int numElements;
public:
	IntegerList(int);
	~IntegerList();
	IntegerList(IntegerList &copy);
	bool isValid(int);
	void setElement(int, int);
	int getElement(int);
};
IntegerList::IntegerList(int s)
{
	size = s;
	numElements = s;
	list = new int [size];
	for(int i=0;i<size;i++)
	{
		list[i] = 0;
	}
}
IntegerList::IntegerList(IntegerList &copy)
{
	size = copy.size;
	numElements = copy.numElements;
	list = new int[size];
	for(int i=0;i<numElements;i++)
	{
		list[i] = copy.list[i];
	}
}
IntegerList::~IntegerList()
{
	delete [] list;
}
bool IntegerList::isValid(int index)
{
	if(index>=0 && index<= (numElements-1))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void IntegerList::setElement(int index, int value)
{
	if(isValid(index))
	{
		if(list[index] == 0)
		{
			list[index] = value;
			numElements++;
		}
	}
	else
	{
		exit(0);
	}
}
int IntegerList::getElement(int index)
{
	if(isValid(index))
	{
		return list[index];
	}
	else
	{
		exit(0);
	}
}


#endif /* INTEGERLIST_H_ */
