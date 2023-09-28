#ifndef LIBRARIAN_H_
#define LIBRARIAN_H_
#include <cstring>
#include <iostream>
#include <fstream>
#include "getch.h"
#include "Login.h"

using namespace std;
class Librarian
{
    string name;
    string libID;
    Login login;

public:
    void createlibrarian()
    {
        system("clear");
        cout << "NEW Librarian ENTRY\n\n";
        cout << "Enter Your First Name only:" << endl;
        cin >> name;
        cout << "Enter The Libraian ID:" << endl;
        cin>> libID;
        login.Register();
        cout << "Librarian Record Created!" << endl;
    }
    string getid() { return libID; }

    void showLibrarian()
    {
        cout << setw(10) << left << "Name:" << name << endl;
        cout << setw(10) << left << "LibID:" << libID << endl;
    }
};
void writesLib()
{
    ofstream fout;
    char ch;
    fout.open("Librarians.dat", ios::binary | ios::app); // write and append data
    do
    {
        Librarian lb;
        system("clear");
        lb.createlibrarian();
        fout.write(reinterpret_cast<char *>(&lb), sizeof(Librarian)); // size of class
        cout << "\nWould you like to add more records? (y/n):" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}
void displayallL() // display all Librarians
{
    ifstream fin;
    Librarian lb;
    system("clear");
    fin.open("Librarians.dat", ios::binary); // read mode
    if (!fin)
    {
        cout << "File Could Not Be Opened" << endl;
        cin.ignore();
        getch();
        return; // press any key and return
    }
    cout << "\n\t\t\tLibrarians List\n";
    cout << "==================================================================" << endl;
    cout << "Name" << setw(20) << right << "LibID" << endl;
    cout << "==================================================================" << endl;
    while (fin.read(reinterpret_cast<char *>(&lb), sizeof(Librarian)))
    {
        lb.showLibrarian();
        cout << endl;
    }
    fin.close();
    cin.ignore();
    getch();
}
void deletelib()
{
    fstream fp;
    Librarian lb;
    string n;
    int flag = 0;
    system("clear");
    cout << "\nDELETE LIBRARIAN" << endl;
    cout << "\nEnter the LibID :" << endl;
    cin >> n;
    fp.open("Librarians.dat", ios::out | ios::in | ios::binary);
    fstream fp2;
    fp2.open("temp.dat", ios::out | ios::binary);
    fp.seekg(0);
    while (fp.read(reinterpret_cast<char *>(&lb), sizeof(Librarian)))
    {
        if (lb.getid() != n)
        {
            fp2.write(reinterpret_cast<char *>(&lb), sizeof(Librarian));
        }
        else
        {
            flag = 1; // librarian found
        }
    }
    fp2.close();
    fp.close();
    remove("Librarians.dat");
    rename("temp.dat", "Librarians.dat"); // data after deletion moved to temp
    if (flag == 1)
    {
        cout << "\nRecord Deleted." << endl;
    }
    else
    {
        cout << "\nRecord not Found." << endl;
    }
    cin.ignore();
    getch();
}
#endif