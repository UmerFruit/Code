/*
 * Array.cpp
 *
 *  Created on: 18-Mar-2023
 *      Author: umerfarooq
 */

#include "Array.h"

int validation(int i)
{
    while(i<0)
    {
        cout<<"Enter Positive value"; cin>>i;       //input validation function
    }
    return i;
}

Array::Array()
{
    mysize = 10;
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = 0;
    }
}
Array::Array(int size)
{
    mysize = size;
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = 0;
    }
}
Array::Array(int *arr, int size)
{
    mysize = validation(size);
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = arr[i];
    }
}
Array::Array(const Array &arr)
{
    mysize = validation(arr.mysize);
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = arr.myarr[i];
    }
}
int Array::getAt(int i)
{
    return myarr[i];
}
void Array::setAt(int i, int val)
{
    myarr[i] = val;
}
Array Array::subArr(int pos, int size)          //sub array of given size
{
    Array temp(size);
    int j = 0;
    for (int i = pos; i < size; i++)
    {
        temp.myarr[j] = myarr[i];
        j++;
    }
    return temp;
}
Array Array::subArr(int pos)            //sub array of size equal to elements
{
    Array temp(mysize - pos);
    int j = 0;
    for (int i = pos; i < mysize; i++)
    {
        temp.myarr[j] = myarr[i];
        j++;
    }
    return temp;
}
int *Array::subArrPointer(int pos, int size)
{
    int *temp = new int[validation(size)];
    int j = 0;
    for (int i = pos; i < size; i++)
    {
        temp[j] = myarr[i];
        j++;
    }
    return temp;
}
int *Array::subArrPointer(int pos)
{
    int *temp = new int[mysize - pos];

    for (int i = pos,j=0; j < (mysize - pos); i++,j++)
    {
        temp[j] = myarr[i];

    }
    return temp;
}
void Array::push_back(int a)
{
    int *temp = new int[mysize + 1];
    for (int i = 0; i < mysize; i++)
    {
        temp[i] = myarr[i];
    }
    temp[mysize] = a;
    delete[] myarr;                 //make temp array and increase size dynamically and append a at end
    mysize++;
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = temp[i];
    }
    delete[] temp;
    temp = 0;
}
int Array::pop_back()
{
    int last = myarr[mysize - 1];

    int *temp = new int[mysize - 1];
    for (int i = 0; i < mysize - 1; i++)
    {
        temp[i] = myarr[i];         //make temp array and decrease size dynamically
    }
    delete[] myarr;
    mysize--;
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = temp[i];
    }
    delete[] temp;
    temp = 0;
    return last;
}
int Array::insert(int idx, int val)
{
    if (idx >= 0 && idx < mysize)
    {
        push_back(0);
        for (int i = mysize - 1; i >= idx; i--)
        {
            int temp = myarr[i];
            myarr[i] = myarr[i + 1];        //shifts elemtents to right
            myarr[i + 1] = temp;
        }
        myarr[idx] = val;
        return 1;
    }
    else
        return -1;
}
int Array::erase(int idx, int val)
{
    if (idx >= 0 && idx < mysize && myarr[idx] == val)
    {
        for (int i = 1; i < mysize - idx; i++)
        {
            int temp = myarr[idx + i];
            myarr[idx + i] = myarr[idx + i - 1];        //shifts elemtents to left
            myarr[idx + i - 1] = temp;
        }
        pop_back();
        return 1;
    }
    else
        return -1;
}
void Array::size()
{
    cout << mysize;
}
int Array::length()
{
    return mysize;
}
void Array::clear()
{
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = 0;
    }
}
int Array::value(int idx)       //same as getter
{
    while(validation(idx)>=mysize)
    {
        cout<<"Enter valid index";
        cin>>idx;
    }
    return myarr[idx];

}
void Array::assign(int idx, int val)            //same as setter
{
    while(validation(idx)>=mysize)
    {
        cout<<"Enter valid index";
        cin>>idx;
    }
    myarr[idx] = val;
}
void Array::copy(const Array &Arr)
{
    mysize = Arr.mysize;
    delete[] myarr;
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = Arr.myarr[i];
    }
}
void Array::copy(const int *arr, int siz)
{
    mysize = siz;
    delete[] myarr;
    myarr = new int[mysize];
    for (int i = 0; i < mysize; i++)
    {
        myarr[i] = arr[i];
    }
}
void Array::display()
{
    for (int i = 0; i < mysize; i++)
    {
        cout << myarr[i] << " ";
    }
    cout << endl;
}
bool Array::isEmpty()
{
    for (int i = 0; i < mysize; i++)
    {
        if (myarr[i] != 0)
        {
            return false;       //if elements are not all zero its not empty
        }
    }
    return true;
}
Array Array::find(int n)
{
    Array indexes(mysize);      //return array of all indexes at which n is found in array
    int j = 0;
    for (int i = 0; i < mysize; i++)
    {
        if (myarr[i] == n)
        {
            indexes.myarr[j] = i;
            j++;
        }
    }
    while(indexes.myarr[mysize-1] == 0)
    {
        pop_back();
        indexes.mysize--;
    }
    return indexes;
}
bool Array::equal(const Array &arr)
{
    for (int i = 0; i < arr.mysize; i++)
    {
        if (myarr[i] != arr.myarr[i])
        {
            return false;
        }
    }
    return true;
}
int Array::sort()
{
    bool acssorted = true;
    bool decsorted = true;
    for (int j = 1; j < mysize; j++)
    {
        for (int i = 0; i < mysize - j; i++)
        {
            if (myarr[i] > myarr[i + 1])
            {
                acssorted = false;
            }
            if (myarr[i] < myarr[i + 1])
            {
                decsorted = false;
            }
        }
    }
    if (acssorted || decsorted)
    {
        return true;
    }

    else
    {
        for (int j = 1; j < mysize; j++)
        {
            for (int i = 0; i < mysize - j; i++)        //sorts in acscending order
            {
                if (myarr[i] > myarr[i + 1])
                {
                    int temp = myarr[i];
                    myarr[i] = myarr[i + 1];
                    myarr[i + 1] = temp;
                }
            }
        }
        return false;
    }
}
void Array::reverse()
{
    for (int i = 0; i < mysize / 2; i++)
    {
        int temp = myarr[i];
        myarr[i] = myarr[mysize - i - 1];       //reverses array
        myarr[mysize - i - 1] = temp;
    }
}
Array::~Array()
{
    delete[] myarr;
}
