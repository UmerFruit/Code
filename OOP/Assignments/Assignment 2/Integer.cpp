/*
 * Integer.cpp
 *
 *  Created on: 18-Mar-2023
 *      Author: umerfarooq
 */

#include "Integer.h"
int length(string str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

Integer::Integer()
{
    myint = 0;
}
Integer::Integer(int i)
{
    myint = i;
}
Integer::Integer(string str)
{
    myint = 0;
    int j = 0;
    while (str[j] != '\0') // similar to stoi() function
        j++;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            myint += static_cast<int>(str[i] - 48) * pow(10, j - i - 1);
        }
        else
        {
            cout << "Not entirely numbers. Error" << endl;
            break;
        }
    }
}

void Integer::set(int i)
{
    myint = i;
}
int Integer::get() const
{
    return myint;
}
int Integer::bitCount()
{
    int temp = myint, count = 0, numbits = 0;
    while (temp != 0)
    {
        temp = temp >> 1;
        numbits++;
    }
    temp = (~myint) + 1; // find 2's complement

    for (int i = 0; i < numbits; i++)
    {
        if (temp & 1)
        {
            count++; // count number of 1's in it
        }
        temp = temp >> 1;
    }
    return count;
}
int Integer::compareTo(Integer i)
{
    if (myint == i.myint)
        return 0;
    else if (myint > i.myint)
        return 1;
    else
        return -1;
}
double Integer::doubleValue()
{
    return static_cast<double>(myint);
}
float Integer::floatValue()
{
    return static_cast<float>(myint);
}
Integer Integer::plus(const Integer &i)
{
    Integer temp;
    temp = myint + i.myint;
    return temp;
}
Integer Integer::minus(const Integer &i)
{
    Integer temp(this->myint - i.myint);
    return temp;
}
Integer Integer::multiple(const Integer &i)
{
    Integer temp;
    temp = myint * i.myint;
    return temp;
}
Integer Integer::divide(const Integer &i)
{
    Integer temp;
    temp = myint / i.myint;
    return temp;
}
int Integer::numberOfLeadingZeros(int i)
{
    int temp = i, numbits = 0;
    while (temp != 0)
    {
        temp = temp >> 1; // count number of bits
        numbits++;
    }
    temp = (~i) + 1;
    int count = 0;
    for (int j = numbits; j >= 0; j--) // doesn't work exactly but its close
    {
        if ((i & (1 << j)) != 0) // check bits one by one from left side of the number's binary
        {
            break; // dont check the entire 32 bits because that will always return 0 after 2's complement
        }
        count++;
    }
    return count;
}
int Integer::numberofTrailingzeros(int i)
{
    int count = 0;
    int temp = (~i) + 1;
    i = temp;
    while (!(i & 1))        //check zeros from the right
    {
        i >>= 1;
        count++;
    }
    return count;
}
string Integer::toBinaryString(int i)
{
    string binary = "";
    int temp = i, numbits = 0;
    while (temp != 0)
    {
        temp = temp >> 1;
        numbits++;
    }
    for (int j = numbits; j > 0; j--)
    {
        char bit = static_cast<char>((i & 1) + 48);         //converts to binary but in reverse
        binary += bit;
        i >>= 1;
    }
    for (int i = 0; i < length(binary) / 2; i++)
    {
        char temp = binary[i];
        binary[i] = binary[length(binary) - i - 1];         //reverse the string for actual binary
        binary[length(binary) - i - 1] = temp;
    }
    return binary;
}
string Integer::toHexString(int i)
{
    string hex = "";
    while (i != 0)
    {
        switch (i % 16)
        {
        case 0:
            hex += '0';
            break;
        case 1:
            hex += '1';
            break;
        case 2:
            hex += '2';
            break;
        case 3:
            hex += '3';
            break;
        case 4:
            hex += '4';
            break;
        case 5:
            hex += '5';
            break;
        case 6:
            hex += '6';
            break;
        case 7:
            hex += '7';
            break;
        case 8:
            hex += '8';
            break;
        case 9:
            hex += '9';
            break;
        case 10:
            hex += 'A';
            break;
        case 11:
            hex += 'B';
            break;
        case 12:
            hex += 'C';
            break;
        case 13:
            hex += 'D';
            break;
        case 14:
            hex += 'E';
            break;
        case 15:            //converts to hexadecimal in string but reversed
            hex += 'F';
            break;
        }
        i /= 16;
    }
    for (int i = 0; i < length(hex) / 2; i++)
    {
        char temp = hex[i];
        hex[i] = hex[length(hex) - i - 1];          //reverse the string for actual representation
        hex[length(hex) - i - 1] = temp;
    }
    return hex;
}
string Integer::toOctString(int i)
{
    string oct = "";
    while (i != 0)
    {
        switch (i % 8)
        {
        case 0:
            oct += '0';
            break;
        case 1:
            oct += '1';
            break;
        case 2:
            oct += '2';
            break;
        case 3:
            oct += '3';
            break;
        case 4:
            oct += '4';
            break;
        case 5:
            oct += '5';
            break;
        case 6:
            oct += '6';
            break;
        case 7:
            oct += '7';             //converts to octal but in reverse
            break;
        }
        i /= 8;
    }
    for (int i = 0; i < length(oct) / 2; i++)
    {
        char temp = oct[i];
        oct[i] = oct[length(oct) - i - 1];      //reverse the string
        oct[length(oct) - i - 1] = temp;
    }
    return oct;
}
