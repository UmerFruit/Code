#ifndef LOGIN_H_
#define LOGIN_H_
#include <cstring>
#include <iostream>
#include <fstream>
#include "getch.h"
using namespace std;
class Login
{
private:
    string username;
    string password;

public:
    Login &Register()
    {
        Login L;
        char choice;
        char l;

        cout << "----------------------" << endl;
        cout << "Type your New Username: " << endl;
        cin >> ws;
        getline(cin, username);
        bool alreadyE = false;
        fstream fp("Usernames.dat", ios::in | ios::binary);
        if (fp)
        {
            while (fp.read(reinterpret_cast<char *>(&L), sizeof(Login)))
            {
                if (L.username == username)
                {
                    alreadyE = true;
                    break;
                }
            }
        }

        if (alreadyE)
        {
            cout << "----------------------" << endl;
            cout << "Same Username existing in database" << endl
                 << "Please use another Username to register" << endl;
            cout << "----------------------" << endl;
            Register();
        }
        else
        {
            fp.close();
            fp.open("Usernames.dat", ios::binary | ios::app);
            cout << "Type your New Password: " << endl;
            password = inputPass();

            fp.write(reinterpret_cast<char *>(this), sizeof(Login));

            cout << "\n----------------------" << endl;
            cout << "Registered successfully" << endl;
            cout << "----------------------" << endl;
        }

        fp.close();
        return *this;
    }
    bool Check()
    {
        string un, pw;
        Login L;
        fstream fp("Usernames.dat", ios::binary | ios::in);
        cout << "----------------------" << endl;
        cout << "Enter the Username: ";
        cin.ignore();
        getline(cin, un);
        cout << un << endl;
        bool exists = false;
        if (fp)
            while (fp.read(reinterpret_cast<char *>(&L), sizeof(Login)) && !exists)
            {
                if (un == L.username)
                {
                    exists = true;
                    break;
                }
            }

        if (!exists)
        {
            cout << "----------------------" << endl;
            cout << "User doesn't exist" << endl;
            cout << "----------------------" << endl;
        }
        else
        {
            cout << "----------------------" << endl;
            cout << "Enter the Password:" << endl;
            cout << "If you have forgotten the password then type \"forgot\". :)" << endl;
            pw = inputPass();
            if (pw == L.password)
            {
                cout << endl;
                cout << "----------------------" << endl;
                cout << "You are now logged in." << endl;
                cout << "----------------------" << endl;
                fp.close();

                return true;
            }
            else if (pw == "forgot")
            {
                cout << "----------------------" << endl;
                cout << "Enter the same Username again." << endl;
                getline(cin, un);
                if (un == L.username)
                {
                    cout << endl;
                    cout << "----------------------" << endl;
                    cout << "You are now logged in" << endl;
                    cout << "----------------------" << endl;
                    fp.close();

                    return true;
                }
                else
                {
                    cout << "\n----------------------" << endl;
                    cout << "Incorrect entry sorry" << endl;
                    cout << "----------------------" << endl;
                    fp.close();

                    return false;
                }
            }
            else
            {
                cout << "\n----------------------" << endl;
                cout << "Incorrect password" << endl;
                cout << "----------------------" << endl;
                fp.close();

                return false;
            }
            fp.close();
        }
        return false;
    }
    string inputPass()
    {
        string password;
        password = "";
        char c;
        while ((c = getch()) != 10) // until newline char \n is entered
        {
            if (c != 127) // if backspace is not pressed
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
        return password;
    }
    void showall()
    {
        Login L;
        fstream fp("Usernames.dat", ios::binary | ios::in | ios::out);
        while (fp.read(reinterpret_cast<char *>(&L), sizeof(Login)))
        {
            L.Display();
        }
    }

    /// Display the credentials
    void Display()
    {
        cout << "----------------------" << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
        cout << "----------------------" << endl;
    }
};
#endif