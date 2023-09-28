#ifndef STUDENT_H_
#define STUDENT_H_
#include <cstring>
#include <iostream>
#include <fstream>
#include "getch.h"
#include "Login.h"
using namespace std;
class Student
{
    string adm_num; // admission no.
    string name;
    string stbook_num; // student book no
    int token;         // total book of student
    Login login;       // for access control
public:
    void createstudent()
    {
        system("clear");
        cout << "NEW STUDENT ENTRY\n\n";
        cout << "Enter The Admission Num:" << endl;
        cin >> adm_num;
        cout << "Enter The Student Name:" << endl;
        cin.ignore();
        getline(cin, name);
        token = 0;
        stbook_num = "";
        login = login.Register();
        cout << "Student Record Created!" << endl;
    }
    void showstudent()
    {
        cout << setw(30) << left << "Admission Number: " << adm_num << endl;
        cout << setw(30) << left << "Student Name : " << name << endl;
        cout << setw(30) << left << "No of Books Issued : " << token << endl;
        if (token == 1)
        {
            cout << setw(30) << left << "Book Number " << stbook_num << endl;
        }
    }
    void modifystudent()
    {
        cout << "\nAdmission No. " << adm_num;
        cout << "\nModify Student Name : ";
        cin.ignore();
        getline(cin, name);
    }
    string getadm_num()
    {
        return adm_num;
    }
    string getstbook_num()
    {
        return stbook_num;
    }
    int gettoken()
    {
        return token;
    }
    void addtoken()
    {
        token = 1;
    }
    void resettoken()
    {
        token = 0;
    }
    void setstbook_num(string t)
    {
        stbook_num = t;
        addtoken();
    }
};
bool findstudent(string admnum)
{
    Student st;
    bool alreadyE = false;
    ifstream fp("Student.dat", ios::in | ios::binary); // read data

    while (fp.read(reinterpret_cast<char *>(&st), sizeof(Student)))
    {
        if (st.getadm_num() == admnum)
        {
            alreadyE = true;
            break;
        }
    }
    return alreadyE;
}
void writestudent()
{
    ofstream fout;
    char ch;
    fout.open("Student.dat", ios::binary | ios::app); // write and append data
    do
    {
        Student st;
        system("clear");
        st.createstudent();
        if(findstudent(st.getadm_num()) == false)
            fout.write(reinterpret_cast<char *>(&st), sizeof(Student)); // size of class
        else
            cout<<"Student Already exists.Try again."<<endl;
        cout << "\nWould you like to add more records? (y/n):" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}
void displaysps(string n) // display specific student
{
    Student st;
    ifstream fin;
    cout << "\nSTUDENT DETAILS" << endl;
    int flag = 0;                                   // if student not found
    fin.open("Student.dat", ios::in | ios::binary); // read data
    while (fin.read(reinterpret_cast<char *>(&st), sizeof(Student)) && flag == 0)
    {
        if (st.getadm_num() == n)
        {
            st.showstudent();
            flag = 1;
        }
    }
    fin.close();
    if (flag == 0) // student not found
    {
        cout << "\nStudent does not exist." << endl;
    }
    cin.ignore();
    getch();
}
void modifystudent()
{
    Student st;
    fstream fp;
    string n;
    int found = 0; // seach book of given data
    system("clear");
    cout << "\nMODIFY STUDENT RECORD" << endl;
    cout << "\nEnter the Admission no. ";
    cin >> n;
    fp.open("Student.dat", ios::in | ios::out | ios::binary);
    int pos = fp.tellg();
    while (fp.read(reinterpret_cast<char *>(&st), sizeof(Student)) && found == 0)
    {

        if (st.getadm_num() == n)
        {
            st.showstudent();
            cout << "\nEnter the new details of student";
            st.modifystudent();
            fp.seekp(pos); // back from current position
            fp.write(reinterpret_cast<char *>(&st), sizeof(Student));
            cout << "\nRecord Updated." << endl;
            found = 1;
        }
        pos = fp.tellg();
    }
    fp.close();
    if (found == 0)
    {
        cin.ignore();
        cout << "\nRecord Not Found." << endl;
    }
    getch(); // press key to get out
}
void deletestudent()
{
    Student st;
    fstream fp;

    string n;
    int flag = 0;
    system("clear");
    cout << "\nDELETE STUDENT" << endl;
    cout << "\nEnter the Admission num :" << endl;
    cin >> n;
    fp.open("Student.dat", ios::in | ios::out | ios::binary);
    fstream fp2;
    fp2.open("temp.dat", ios::out | ios::binary);
    fp.seekg(0);
    while (fp.read(reinterpret_cast<char *>(&st), sizeof(Student)))
    {
        if (st.getadm_num() != n)
        {
            fp2.write(reinterpret_cast<char *>(&st), sizeof(Student));
        }
        else
        {
            flag = 1; // student found
        }
    }
    fp2.close();
    fp.close();
    remove("Student.dat");
    rename("temp.dat", "Student.dat"); // data after deletion moved to temp
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
void displayalls() // display all students
{
    ifstream fin;
    Student st;
    system("clear");
    fin.open("Student.dat", ios::binary); // read mode
    if (!fin)
    {
        cout << "File Could Not Be Opened" << endl;
        cin.ignore();
        getch();
        return; // press any key and return
    }
    cout << "\n\t\t\tStudent List\n";
    cout << "==================================================================" << endl;
    cout << "Admission No." << setw(15) << right << "Name" << setw(20) << "Book Issued" << endl;
    cout << "==================================================================" << endl;
    while (fin.read(reinterpret_cast<char *>(&st), sizeof(Student)))
    {
        st.showstudent();
        cout << endl;
    }
    fin.close();
    cin.ignore();
    getch();
}

#endif