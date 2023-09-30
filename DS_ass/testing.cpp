#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "getch.h"
using namespace std;

class ActionLog
{
private:
    ofstream logFile;

public:
    ActionLog(const string &filename)
    {
        logFile.open(filename, ios::app);
    }

    ~ActionLog()
    {
        if (logFile.is_open())
        {
            logFile.close();
        }
    }

    void logAction(string name, string action)
    {
        if (logFile.is_open())
        {
            time_t currentTime = time(nullptr);
            string localTime = ctime(&currentTime);

            logFile << localTime << endl
                    << "User:" << name << "\nAction:" << action << endl;
        }
    }
};

ActionLog logging("log.txt");

class Book
{
protected:
    string Title;
    string IBN;

public:
    Book()
    {
    }
    Book(string T, string I)
    {
        Title = T;
        IBN = I;
    }
    void setBook()
    {
        cout << "Enter Book Name:" << endl;
        if (getch() == '\n')
        {
            cin.ignore();
        }
        getline(cin, Title);
        cout << "Enter IBN Number:" << endl;
        getline(cin, IBN);
    }

    void WriteBookFile()
    {
        ofstream fout;
        char ch;
        fout.open("Book.bin", ios::binary | ios::app);
        do
        {
            Book bk;
            bk.setBook();
            fout.write(reinterpret_cast<char *>(&bk), sizeof(Book));
            cout << "Would you like to add more records?" << endl;
            cin >> ch;
        } while (ch == '1');
        fout.close();
    }

    void ReadBookFile()
    {
        ifstream fin("Book.bin", ios::binary);
        Book bk;
        while (!fin.eof())
        {
            fin.read(reinterpret_cast<char *>(&bk), sizeof(Book));
        }
        fin.close();
    }

    void RemoveBookByIBN(string ISBN)
    {
        ifstream fin("Book.bin", ios::binary);
        ofstream temp("temp.bin", ios::binary);

        Book bk;
        bool found = false;

        while (fin.read(reinterpret_cast<char *>(&bk), sizeof(Book)))
        {
            if (bk.IBN == ISBN)
            {
                found = true;
                cout << "Book with ISBN " << ISBN << " removed." << endl;
            }
            else
            {
                temp.write(reinterpret_cast<char *>(&bk), sizeof(Book));
            }
        }

        fin.close();
        temp.close();

        if (found)
        {
            remove("Book.bin");
            rename("temp.bin", "Book.bin");
        }
        else
        {
            cout << "Book with ISBN " << ISBN << " not found." << endl;
            remove("temp.bin");
        }
    }

    void DisplayAllBooks()
    {
        ifstream fin("Book.bin", ios::binary);

        if (!fin)
        {
            cout << "Error opening file." << endl;
            return;
        }

        Book bk;

        while (fin.read(reinterpret_cast<char *>(&bk), sizeof(Book)))
        {
            cout << "Title: " << bk.Title << "\tISBN: " << bk.IBN << endl;
        }

        fin.close();
    }
};

class Student
{
private:
    string st_Name;
    string RollNo;
    string st_Email;
    string st_Password;

public:
    Student()
    {
    }
    Student(string n, string p, string rn, string email)
    {
        st_Name = n;
        st_Password = p;
        st_Email = email;
        RollNo = rn;
    }
    void setStudent()
    {
        cout << "Enter Student Name:" << endl;
        getline(cin, st_Name);
        cout << "Enter Roll Number:" << endl;
        getline(cin, RollNo);
        cout << "Enter Email:" << endl;
        getline(cin, st_Email);
        cout << "Enter Password:" << endl;
        getline(cin, st_Password);
    }

    string getEmail() const
    {
        return st_Email;
    }

    string getPassword() const
    {
        return st_Password;
    }

    void WriteStudentData()
    {
        ofstream fout;
        char ch;
        fout.open("StudentData.bin", ios::binary | ios::app);
        do
        {
            Student st;
            st.setStudent();
            fout.write(reinterpret_cast<char *>(&st), sizeof(Student));
            cout << "Would you like to add more records?" << endl;
            cin >> ch;
        } while (ch == '1');
        fout.close();
    }

    void ReadStudentData(string name)
    {
        ifstream fin("StudentData.bin", ios::binary);
        Student st;
        while (!fin.eof())
        {
            fin.read(reinterpret_cast<char *>(&st), sizeof(Student));
            if (name == st.st_Name)
            {
                setName(name);
            }
        }
        fin.close();
    }
    void setName(string Name)
    {
        st_Name = Name;
    }
    string getName()
    {
        return st_Name;
    }

    void DisplayStudent()
    {
        ifstream fin("StudentData.bin", ios::binary);

        if (!fin)
        {
            cout << "Error opening file." << endl;
            return;
        }

        Student st;
        while (fin.read(reinterpret_cast<char *>(&st), sizeof(Student)))
        {
            cout << "Name: " << st.st_Name << "\tRoll No.: " << st.RollNo << endl;
        }

        fin.close();
    }
};

class Library : public Book, public Student
{
protected:
    string ad_name;
    string ad_email;
    string ad_pass;
    string SUPERID;
    string SUPERPASS;

public:
    Library()
    {
    }
    Library(string an, string ae, string ap) : Book(), Student()
    {
        SUPERID = "attah.ullah@nu.edu.pk";
        SUPERPASS = "attah1234$";
        ad_name = an;
        ad_email = ae;
        ad_pass = ap;
    }

    string getAdminEmail()
    {
        return ad_email;
    }

    string getAdminPass()
    {
        return ad_pass;
    }

    void setAdmin()
    {
        cout << "Enter Admin Name:" << endl;
        getline(cin, ad_name);
        cout << "Enter Admin Email:" << endl;
        getline(cin, ad_email);
        cout << "Enter Admin Password:" << endl;
        getline(cin, ad_pass);
    }

    void WriteAdminData()
    {
        ofstream fout("Admin.bin", ios::binary);
        char ch;
        fout.open("Admin.bin", ios::binary | ios::app);
        do
        {
            Library li;
            li.setAdmin();
            fout.write(reinterpret_cast<char *>(&li), sizeof(Library));
            cout << "Would you like to add more records?" << endl;
            cin >> ch;
        } while (ch == '1');
        fout.close();
    }

    void ReadAdminData()
    {
        ifstream fin("Admin.bin", ios::binary);
        Library li;
        while (!fin.eof())
        {
            fin.read(reinterpret_cast<char *>(&li), sizeof(Library));
        }
        fin.close();
    }

    void StudentLogin()
    {
        string email;
        string pass;
        string ibn;
        bool Found = false;
        int ch;
        Student st;

        ifstream fin("StudentData.bin", ios::binary);

        if (!fin)
        {
            cout << "File not Open" << endl;
            return;
        }
        else
        {
            cout << "OPENED";
        }

        cout << " Enter Your Email To Login : ";
        if (getch() == '\n')
        {
            cin.ignore();
        }
        getline(cin, email);
        cout << "\n Enter Your Password : ";
        getline(cin, pass);
        cout << endl;
        logging.logAction(st.getName(), "Login");
        cout << endl;

        cout << "Debug Info: Entered Email: " << email << ", Password: " << pass << endl;

        while (fin.read(reinterpret_cast<char *>(&st), sizeof(Student)))
        {
            cout << "Debug Info: Read a student record with Email: " << st.getEmail() << ", Password: " << st.getPassword() << endl;
            if (st.getEmail() == email && st.getPassword() == pass)
            {
                Found = true;
                cout << "Found a matching student!" << endl;
                break; // Exit the loop if a match is found
            }
        }

        fin.close();

        if (!Found)
        {
            cout << "No Record Found!" << endl;
        }

        if (Found)
        {
            cout << "Press 1 to Issue Book : ";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case 1:
                cout << " Which Book You Want To Issue : \n-----------------------" << endl;
                DisplayAllBooks();
                cout << "-----------------------\n Write IBN Number Of Book To Issue : ";
                cin.ignore();
                getline(cin, ibn);
                RemoveBookByIBN(ibn);
                cout << endl;
                logging.logAction(st.getName(), "Issued a book");
                cout << endl;
                break;
            default:
                cout << "No Option" << endl;
            }
        }
    }

    void AdminLogin()
    {
        string email;
        string pass;
        string ibn;
        int ch;
        bool Found = false;
        Library L;

        ifstream fin("AdminData.bin", ios::binary);

        if (!fin)
        {
            cout << "File not Found!" << endl;
        }

        cout << "Enter Email to Login : ";
        if (getch() == '\n')
        {
            cin.ignore();
        }
        getline(cin, email);
        cout << "Enter the Password : ";
        getline(cin, pass);
        logging.logAction(ad_name, "Login");
        cout << endl;

        while (fin.read(reinterpret_cast<char *>(&L), sizeof(Library)))
        {
            if (L.getAdminEmail() == email && L.getAdminPass() == pass)
            {
                Found = true;
                cout << "Found a matching admin!" << endl;
                break; // Exit the loop if a match is found
            }
        }

        fin.close();

        if (Found)
        {
            cout << "What Actions You Want To Perform?\n->Press 1 to Display Books\n->Press 2 to Add New Book\nPress 3 to Remove Book" << endl;

            switch (ch)
            {
            case 1:
                cout << "    LIST OF BOOKS\n--------------------\n"
                     << endl;
                DisplayAllBooks();
                cout << "\n--------------------\n"
                     << endl;
                logging.logAction(ad_name, "Display books");
                break;
            case 2:
                WriteBookFile();
                logging.logAction(ad_name, "Added a book");
                break;
            case 3:
                cout << "Enter IBN of Book to Remove from List : ";
                getline(cin, ibn);
                RemoveBookByIBN(ibn);
                logging.logAction(ad_name, "Removed book");
                break;
            default:
                cout << "Wrong Option!" << endl;
            }
        }
    }
};

int main()
{
    Book b1;
    b1.WriteBookFile();
    cout<<"Chal gya."<<endl;
    b1.DisplayAllBooks();
    cout<<"Chal gya."<<endl;
    b1.RemoveBookByIBN("34756");
    cout<<"Chal gya."<<endl;
    b1.DisplayAllBooks();
    cout<<"Chal gya."<<endl;
    //b1.ReadBookFile();          //ye function kya kar raha hai? faaltu lag raha hai mujhe

    Student s1;
    s1.WriteStudentData();

    Library l1;
    l1.WriteStudentData();
    l1.DisplayStudent();
    l1.StudentLogin();
    l1.WriteStudentData();
    l1.DisplayStudent();
    //l1.ReadStudentData();
    //l1.WriteLibraryData();
    //l1.ReadLibraryData();

    return 0;
}