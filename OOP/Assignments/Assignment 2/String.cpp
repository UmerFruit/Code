/*
 * String.cpp
 *
 *  Created on: 18-Mar-2023
 *      Author: umerfarooq
 */

#include "String.h"

String::String()
{
    string = new char[50];
}
String::String(char *str)
{
    string = new char[100];
    int i = 0;
    while (str[i] != '\0')
    {
        string[i] = str[i];
        i++;
    }
}
String::String(const String &str)
{
    string = str.string;
    int i = 0;
    while (str.string[i] != '\0')
    {
        string[i] = str.string[i];
        i++;
    }
}
String::String(int x)
{
    string = new char[x];
}
char String::getAt(int i)
{
    return string[i];
}
void String::setAt(int i, char c)
{
    string[i] = c;
}
String String::substr(int pos, int len)
{
    String str1(len);
    int j = 0;
    for (int i = pos; i < len; i++)
    {
        str1.string[j++] = string[i];
    }
    return str1;
}
String String::substr(int pos)
{
    int size=0;
    while (string[size] != '\0')
    {
        size++;
    }
    String str1(size-pos);
    int j = 0;
    int i = pos;
    while (string[i] != '\0')
    {
        str1.string[j++] = string[i];
        i++;
    }
    return str1;
}
void String::append(char a)
{
    char *ptr = string;
    int i = 0;
    while (string[i] != '\0')
    {
        ptr++;
        i++;
    }
    *ptr = a;
    *(ptr + 1) = '\0';
}
void String::append(String str)
{
    char *ptr = string;
    int i = 0;
    while (string[i] != '\0')
    {
        ptr++;
        i++;
    }
    for (int i = 0; str.string[i] != '\0'; i++)
    {
        ptr[i] = str.string[i];
    }
}
void String::append(char *str)
{
    char *ptr = string;
    int i = 0;
    while (string[i] != '\0')
    {
        ptr++;
        i++;
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        *(ptr + i) = str[i];
    }
}
int String::length()
{
    int i = 0;
    while (string[i] != '\0')
    {
        i++;
    }
    return i;
}
char *String::tocstring()
{
    return string;
}

void String::display()
{
    cout << string << endl;
}
bool String::isEmpty()
{
    if (string[0] == '\0')
        return true;
    else
        return false;
}
void String::copy(const String &str)
{
    int i;
    for (i = 0; str.string[i] != '\0'; i++)
    {
        string[i] = str.string[i];
    }
    string[i] = '\0';
}
void String::copy(const char *str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        string[i] = str[i];
    }
    string[i] = '\0';
}
int String::find(char c)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == c)
        {
            return i;
        }
    }
    return -1;
}
bool String::equal(String str)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != str.string[i])
        {
            return false;
        }
    }
    return true;
}
int String::stoi()
{
    int number = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 48 && string[i] <= 57)
        {
            number += static_cast<int>(string[i] - 48) * pow(10, length() - i - 1);
        }
        else
        {
            cout << "Not entirely numbers. Error" << endl;
            return 0;
        }
    }
    return number;
}
String::~String()
{
    delete string;
}
