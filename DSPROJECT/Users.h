#ifndef USERS_H_
#define USERS_H_
#include "Headers.h"
using namespace std;
class truckdriver
{
    string name;
    string username;
    string password;
    bool allocated;
    // Graph pew;     //fuck u umer

public:
    truckdriver()
    {
        name = "";
        username = "";
        password = "";
        allocated = 0;
    }
    truckdriver(string name, string usrname, string pass)
    {
        this->name = name;
        username = usrname;
        password = pass;
        allocated = 0;
    }
    void setname(string n) { name = n; }
    void setusrname(string usr) { username = usr; }
    void setpass(string pass) { password = pass; }
    void setallocated(bool x) { allocated = x; }
    string getname() { return name; }
    string getusrname() { return username; }
    string getpass() { return password; }
    bool getallocated() { return allocated; }

    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    }
};
class controller
{
    string name;
    string username;
    string password;
    // Graph pew;

public:
    controller()
    {
        name = "";
        username = "";
        password = "";
    }
    controller(string name, string usrname, string pass)
    {
        this->name = name;
        username = usrname;
        password = pass;
    }
    void setname(string n) { name = n; }
    void setusrname(string usr) { username = usr; }
    void setpass(string pass) { password = pass; }
    string getname() { return name; }
    string getusrname() { return username; }
    string getpass() { return password; }
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    }
};
#endif