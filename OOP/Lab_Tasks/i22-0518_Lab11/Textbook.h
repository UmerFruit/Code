/*
 * Textbook.h
 *
 *  Created on: 05-Apr-2023
 *      Author: umerfarooq
 */

#ifndef TEXTBOOK_H_
#define TEXTBOOK_H_
#include <iostream>
#include <string>
using namespace std;
class Textbook {
private:
	string title;
    string  author;
	int book_id;
public:
	Textbook();
	Textbook(string t,string a,int i);
	void set(string t,string a,int i);
	void print();
};

#endif /* TEXTBOOK_H_ */
