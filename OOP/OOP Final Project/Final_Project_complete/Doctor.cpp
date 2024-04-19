/*
 * Doctor.cpp
 *
 *  Created on: 10-May-2023
 *      Author: umerfarooq
 */
#include "Doctor.h"

Doctor::Doctor(string i, string n, string u, string p, string s)
{
	id = i;
	name = n;
	username = u;
	password = p;
	spec = s;
	for (int i = 0; i < 10; i++)
	{
		appreqs[i] = 0;
	}
}

int Doctor::rtn()
{
	Doctor temp;
	ifstream fin("doctors.dat", ios::binary);
	while (fin.good())
	{
		fin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
		if (username.compare(temp.username) == 0)
		{
			return stoi(temp.id) - 1;
		}
	}
	return 0;
}
bool Doctor::dr_login()
{
	int flag = 0;
	Doctor temp;
	ifstream fin("doctors.dat", ios::binary);
	while (fin.good())
	{
		fin.read(reinterpret_cast<char *>(&temp), sizeof(temp));
		if (temp.username == username && temp.password == password)
		{
			cout << "Login succesful" << endl;
			return true;
		}
	}

	cout << "\nLogin unsucessful" << endl;
	return false;
}

void Doctor::login()
{
	cout << "Enter Username : " << endl;
	cin >> username;
	cin.ignore();
	cout << "Enter Password : " << endl;

	password = "";
	char c;
	while ((c = getch()) != 10)
	{
		if (c != 127)
		{
			password += c;
			cout << '*'; // display asterisks instead of actual password characters
		}
		else
		{
			cout << "\r" << setw(100) << setfill(' ') << ""
				 << "\r";
			password.pop_back();
			int size = 0;
			for (int i = 0; password[i] != '\0'; i++)
			{
				size++;
			}
			for (int i = 0; i < size; i++)
			{
				cout << "*";
			}
		}
	}
}

ostream &operator<<(ostream &out, Doctor &t)
{
	out << "Doctor Name: " << t.name << endl;
	out << "Doctor ID: " << t.id << endl;
	out << "Specialization: " << t.spec << endl;
	return out;
}

string &Doctor::getSpec()
{
	return spec;
}

int *Doctor::getAppreqs()
{
	return appreqs;
}
