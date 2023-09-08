/*
 * String.h
 *
 *  Created on: 18-Mar-2023
 *      Author: umerfarooq
 */

#ifndef STRING_H_
#define STRING_H_

#include <iostream>
using namespace std;

class String
{
private:
    char *string;

public:
    // provide definitions of following functions...
    String();                        // default constructor
    String(char *str);               // initializes the string with constant cstring
    String(const String &);          // copy constructor
    String(int x);                   // initializes a string of pre-defined size
    char getAt(int i);               // returns the character at index [x]
    void setAt(int i, char c);       // set the character at index [x]
    String substr(int pos, int len); // returns a substring of length len from 'pos'
    String substr(int pos);          // returns substring from the given position to the end.
    void append(char a);             // append a char at the end of string
    void append(String str);         // append a String at the end of string
    void append(char *str);          // append a constant c string at the end of string
    int length();                    // returns the length of string
    char *tocstring();               // converts a String to c-string
    void display();                  // displays the string ..
    bool isEmpty();                  // returns true if string is empty..
    void copy(const String &);       // Copy one string to another ...
    void copy(const char *);         // copy cstring to String...
    int find(char);                  // returns the index of character being searched.
    bool equal(String);              // should return true if both strings are same
    int stoi();                      // function for converting a string to integer.
    ~String();                       // destructor...
};

#endif /* STRING_H_ */
