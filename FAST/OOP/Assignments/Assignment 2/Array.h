/*
 * Array.h
 *
 *  Created on: 18-Mar-2023
 *      Author: umerfarooq
 */

#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>
using namespace std;
class Array
{
    int *myarr;
    int mysize;

public:
    // provide definitions of following functions...
    Array();                        // a default constructor
    Array(int size);                // a parametrized constructor initializing an Array of predefined
    Array(int *arr, int size);      // initializes the Array with an existing Array
    Array(const Array &);           // copy constructor
    int getAt(int i);               // returns the integer at index [i]
    void setAt(int i, int val);     // set the value at index [i]
    Array subArr(int pos, int siz); // returns a sub-Array of size siz starting from

    Array subArr(int pos);                 // returns a sub-Array from the given position to the end.
    int *subArrPointer(int pos, int size); // returns an array of size siz starting from

    int *subArrPointer(int pos);  // returns an array from the given position to the end.
    void push_back(int a);        // adds an element to the end of the array
    int pop_back();               // removes and returns the last element of the array
    int insert(int idx, int val); /* inserts the value val at idx. Returns 1 for a
   successful insertion and -1 if idx does not exists or is invalid. Shift the
   elements after idx to the right.*/
    int erase(int idx, int val);  /* erases the value val at idx. Returns 1 for a
    successful deletion and -1 if idx does not exists or is invalid. Shift the
    elements after idx to the left.*/
    void size();
    int length();                        // returns the size of the Array
    void clear();                        // clears the contents of the Array
    int value(int idx);                  // returns the value at idx
    void assign(int idx, int val);       // assigns the value val to the element at index idx
    void copy(const Array &Arr);         // Copy the passed Array
    void copy(const int *arr, int size); // copy the passed array
    void display();                      // displays the Array
    bool isEmpty();                      // returns true if the Array is empty
    Array find(int);                     // returns an Array containing all the indexes of integer being searched
    bool equal(const Array &);           // should return true if both Arrays are same
    int sort();                          // sorts the Array. Returns true if the array is already sorted
    void reverse();                      // reverses the contents of the array
    ~Array();                            // destructor...
};

#endif /* ARRAY_H_ */
