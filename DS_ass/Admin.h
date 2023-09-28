#ifndef ADMIN_H_
#define ADMIN_H_
#include <cstring>
#include <iostream>
#include <fstream>
#include "getch.h"
#include "Login.h"
using namespace std;
class Admin
{
    string name;
    string adminID;
    Login login;

public:
    void createadmin()
    {
        system("clear");
        cout << "NEW ADMIN ENTRY\n\n";
        cout << "Enter Your Name:" << endl;
        cin >> name;
        cout << "Enter The Admin ID:" << endl;
        cin.ignore();
        getline(cin, adminID);
        login = login.Register();
        cout << "Admin Record Created!" << endl;
    }
    string getid() { return adminID; }
    void showadmin()
    {
        cout << setw(10) << left << "Name:" << name << endl;
        cout << setw(10) << left << "AdminID:" << adminID << endl;
    }
};
void writesadm()
{
    ofstream fout;
    char ch;
    fout.open("Admins.dat", ios::binary | ios::app); // write and append data
    do
    {
        Admin am;
        system("clear");
        am.createadmin();
        fout.write(reinterpret_cast<char *>(&am), sizeof(Admin)); // size of class
        cout << "\nWould you like to add more records? (y/n):" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}
void displayallA() // display all admins
{
    ifstream fin;
    Admin am;
    system("clear");
    fin.open("Admins.dat", ios::binary); // read mode
    if (!fin)
    {
        cout << "File Could Not Be Opened" << endl;
        cin.ignore();
        getch();
        return; // press any key and return
    }
    cout << "\n\t\t\tAdmins List\n";
    cout << "==================================================================" << endl;
    cout << "Name" << setw(20) << right << "AdminID" << endl;
    cout << "==================================================================" << endl;
    while (fin.read(reinterpret_cast<char *>(&am), sizeof(Admin)))
    {
        am.showadmin();
        cout << endl;
    }
    fin.close();
    cin.ignore();
    getch();
}
void deleteadm()
{
    fstream fp;
    Admin am;
    string n;
    int flag = 0;
    system("clear");
    cout << "\nDELETE ADMIN" << endl;
    cout << "\nEnter the AdminID :" << endl;
    cin >> n;
    fp.open("Admins.dat", ios::in | ios::out | ios::binary);
    fstream fp2;
    fp2.open("temp.dat", ios::out | ios::binary);
    fp.seekg(0);
    while (fp.read(reinterpret_cast<char *>(&am), sizeof(Admin)))
    {
        if (am.getid() != n)
        {
            fp2.write(reinterpret_cast<char *>(&am), sizeof(Admin));
        }
        else
        {
            flag = 1; // Admin found
        }
    }
    fp2.close();
    fp.close();
    remove("Admins.dat");
    rename("temp.dat", "Admins.dat"); // data after deletion moved to temp
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