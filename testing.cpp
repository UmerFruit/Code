#include "Headers.h"
using namespace std;
class student
{
    string adm_num; // admission no.
    string name;
    string stbook_num; // student book no
    int token;         // total book of student
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
        cout << "Student Record Created!" << endl;
    }
    void showstudent()
    {
        cout << "Admission Number: " << adm_num << endl;
        cout << "Student Name : " << name << endl;
        cout << "No of Books Issued : " << token << endl;
        if (token == 1)
        {
            cout << "Book Number " << stbook_num << endl;
        }
    }
    void modifystudent()
    {
        cout << "\nAdmission No. " << adm_num;
        cout << "\nModify Student Name : ";
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
int main()
{
    student s;
    s.createstudent();
    s.showstudent();
    s.modifystudent();
    s.showstudent();
    s.setstbook_num("51234");
    s.showstudent();
}
