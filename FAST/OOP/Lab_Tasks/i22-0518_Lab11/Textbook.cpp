/*
 * Textbook.cpp
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#include "Textbook.h"

Textbook::Textbook()
{
	title[0] = '\0';
	author[0] = '\0';
	book_id = 0;
}
Textbook::Textbook(string t,string a,int i):title(t),author(a),book_id(i) {}
void Textbook::set(string t,string a,int i)
{
	title= t;
	author= a;
	book_id= i;
}
void Textbook::print()
{
	cout<<"Title : "<<title<<endl;
	cout<<"Author : "<<author<<endl;
	cout<<"Book ID : "<<book_id<<endl;
}
