#include "Headers.h"
using namespace std;
class Book
{
private:
    string book_num;    // bookno.
    string book_name;   // bookname
    string author_name; // authorname
public:
    void createbook()
    {
        system("clear");
        cout << "NEW BOOK ENTRY\n\n";
        cout << "Enter Book Number:" << endl;
        cin >> book_num;
        cout << "Enter Book Name:" << endl;
        cin.ignore();
        getline(cin, book_name);
        cout << "Enter Author Name:" << endl;
        getline(cin, author_name);
        cout << "Book Created!" << endl;
    }
    void showbook()
    {
        cout << setw(20) << left << "Book Number: " << book_num << endl;
        cout << setw(20) << left << "Enter Book Name: " << book_name << endl;
        cout << setw(20) << left << "Enter Author Name: " << author_name << endl;
    }
    void modifybook()
    {
        cout << "Book Number: " << book_num << endl;
        cout << "Modify Book Name:" << endl;
        getline(cin, book_name);
        cout << "Modify Author's Name :" << endl;
        getline(cin, author_name);
    }

    string getbook_num() // string getter
    {
        return book_num;
    }

}; // class ends here

class Student
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
        cout << setw(20) << left << "Admission Number: " << adm_num << endl;
        cout << setw(20) << left << "Student Name : " << name << endl;
        cout << setw(20) << left << "No of Books Issued : " << token << endl;
        if (token == 1)
        {
            cout << setw(20) << left << "Book Number " << stbook_num << endl;
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
};          // class ends here
Book bk;    // book class object
Student st; // student class object

void bookdeposit()
{
    fstream fp, fp1;
    string sn, bn;
    int found = 0, flag = 0, day, fine;
    system("clear");
    cout << "\nBOOK DEPOSIT"<<endl;
    cout << "\nEnter Admission num."<<endl;
    cin >> sn;
    fp.open("Student.dat", ios::in | ios::out | ios::binary);
    fp1.open("Book.dat", ios::in | ios::out | ios::binary);
    while (fp.read(reinterpret_cast<char *>(&st), sizeof(Student)) && found == 0)
    {
        if (st.getadm_num() == sn) // compare admsn no.
        {
            found = 1;
            if (st.gettoken() == 1) // if book issued
            {
                while (fp1.read(reinterpret_cast<char *>(&bk), sizeof(Book)) && flag == 0)
                {
                    if (bk.getbook_num() == st.getstbook_num())
                    {
                        flag = 1;
                        bk.showbook();
                        cout << "\nBook Deposited In No. Of Days?"<<endl;
                        cin >> day;
                        if (day > 15)
                        {
                            fine = (day - 15) * 15;
                            cout << "\nFine = " << fine<<endl;
                        }
                        st.resettoken();
                        int pos = -1 * sizeof(st);
                        fp.seekg(pos, ios::cur);
                        fp.write(reinterpret_cast<char *>(&st), sizeof(Student));
                        cout << "\nBook Deposited Successfully"<<endl;
                    }
                }
                if (flag == 0)
                {
                    cout << "Book No. Does Not Exists";
                }
            }

            else
            {

                cout << "No Book Issued";
            }
        }
    }
    if (found == 0)
    {
        cout << "Student Record Not Exist"<<endl;
    }
    getch();
    fp.close();
    fp1.close();
}
int main()
{
    bookdeposit();
}
