#include <iostream>
#include <iomanip> //input-output manipulator
#include <cstring>
#include <fstream>
#include "getch.h"
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
};          // class ends here
Book bk;    // book class object
Student st; // student class object

void writebook()
{
    ofstream fout;
    char ch;
    fout.open("Book.dat", ios::binary | ios::app); // write and append data
    do
    {
        system("clear");
        bk.createbook();
        fout.write(reinterpret_cast<char *>(&bk), sizeof(Book)); // size of class
        cout << "\nWould you like to add more records? (y/n):" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

void writestudent()
{
    ofstream fout;
    char ch;
    fout.open("Student.dat", ios::binary | ios::app); // write and append data
    do
    {
        system("clear");
        st.createstudent();
        fout.write(reinterpret_cast<char *>(&st), sizeof(Student)); // size of class
        cout << "\nWould you like to add more records? (y/n):" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}
void displayspb(string n) // display specific book
{
    ifstream fin;
    cout << "\nBOOK DETAILS" << endl;
    int flag = 0;                                // if book not found
    fin.open("Book.dat", ios::in | ios::binary); // read data
    while (fin.read(reinterpret_cast<char *>(&bk), sizeof(Book)) && flag == 0)
    {
        if (bk.getbook_num() == n)
        {
            bk.showbook();
            flag = 1;
        }
    }
    fin.close();
    if (flag == 0) // book not found
    {
        cout << "\nBook does not exist." << endl;
    }
    cin.ignore();
    getch();
}
void displaysps(string n) // display specific student
{
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
void modifybook()
{
    fstream fp;
    string n;
    int found = 0; // seach book of given data
    system("clear");
    cout << "\nMODIFY BOOK RECORD" << endl;
    cout << "\nEnter The Book No. ";
    cin >> n;
    fp.open("Book.dat", ios::in | ios::out | ios::binary);
    int pos;
    while (fp.read(reinterpret_cast<char *>(&bk), sizeof(Book)) && found == 0)
    {
        if (bk.getbook_num() == n)
        {
            bk.showbook();
            cout << "\nEnter the new details for book." << endl;
            cin.ignore();
            bk.modifybook();
            fp.seekp(pos); // back from current position
            fp.write(reinterpret_cast<char *>(&bk), sizeof(Book));
            cout << "\nRecord Updated" << endl;
            found = 1;
        }
        pos = fp.tellg();
    }
    fp.close();
    if (found == 0)
    {
        cin.ignore();
        cout << "\nRecord Not Found" << endl;
    }
    getch(); // press key to get out
}
void modifystudent()
{
    fstream fp;
    string n;
    int found = 0; // seach book of given data
    system("clear");
    cout << "\nMODIFY STUDENT RECORD" << endl;
    cout << "\nEnter the Admission no. ";
    cin >> n;
    fp.open("Student.dat", ios::in | ios::out | ios::binary);
    int pos;
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
void deletebook()
{
    fstream fp;
    string n; // book no.
    int flag = 0;
    system("clear");
    cout << "\nDELETE BOOK." << endl;
    cout << "\nEnter the Book num:" << endl;
    cin >> n;
    fp.open("Book.dat", ios::in | ios::out | ios::binary);
    fstream fp2;                                  // New object
    fp2.open("Temp.dat", ios::out | ios::binary); // temp having data else than that to be deleted
    fp.seekg(0, ios::beg);
    while (fp.read(reinterpret_cast<char *>(&bk), sizeof(Book)))
    {
        if (bk.getbook_num() != n)
        {
            fp2.write(reinterpret_cast<char *>(&bk), sizeof(Book));
        }
        else
        {
            flag = 1; // student found
        }
    }
    fp2.close();
    fp.close();
    remove("Book.dat");
    rename("Temp.dat", "Book.dat"); // data after deletion moved to temp
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
        cout<<endl;
    }
    fin.close();
    cin.ignore();
    getch();
}
void displayallb()
{
    ifstream fin;
    system("clear");
    fin.open("Book.dat", ios::in | ios::binary); // read mode
    if (!fin)
    {
        cout << "File Could Not Be Open";
        cin.ignore();
        getch();
        return; // press any key and return
    }
    cout << "\n\t\t\tBook List\n";
    cout << "==================================================================" << endl;
    cout << "Book Number" << setw(20) << right << "Book Name" << setw(25) << "Book Author" << endl;
    cout << "==================================================================" << endl;
    while (fin.read(reinterpret_cast<char *>(&bk), sizeof(Book)))
    {
        bk.showbook();
    }
    fin.close();
    cin.ignore();
    getch();
}
void bookissue()
{
    fstream fp1, fp;
    string sn, bn;
    int found = 0, flag = 0;
    system("clear");
    cout << "\nBOOK ISSUE" << endl;
    cout << "\nEnter Admission num. ";
    cin >> sn;
    fp.open("Student.dat", ios::in | ios::out | ios::binary);
    fp1.open("Book.dat", ios::in | ios::out | ios::binary);
    int pos = fp.tellg();
    while (fp.read(reinterpret_cast<char *>(&st), sizeof(Student)) && found == 0)
    {
        if (st.getadm_num() == sn) // compare admsn no.
        {
            found = 1;
            if (st.gettoken() == 0) // if book not issued
            {
                cout << "\nEnter The Book No. ";
                cin >> bn;

                while (fp1.read(reinterpret_cast<char *>(&bk), sizeof(Book)) && flag == 0)
                {
                    if (bk.getbook_num() == bn) // compare book no.
                    {
                        flag = 1;
                        st.addtoken();
                        st.setstbook_num(bk.getbook_num()); // pass book no.
                        fp.seekg(pos);
                        fp.write(reinterpret_cast<char *>(&st), sizeof(Student));
                        cout << "\n\nBook Issued Successfully\n\nPlease Note The Book Issue Date On Backside Of Your Book And Return Book Within 15 Days, Otherwise Fine Of 15 Rs Per Day" << endl;
                    }
                }
                if (flag == 0)
                {
                    cout << "Book No. Does Not Exist" << endl;
                }
            }
            else
            {

                cout << "You Have Not Returned The Last Book" << endl;
            }
        }
        pos = fp.tellg();
    }
    if (found == 0)
    {
        cout << "Student Record Not Exist" << endl;
    }
    fp.close();
    fp1.close();
    cin.ignore();
    getch();
}
void bookdeposit()
{
    fstream fp, fp1;
    string sn, bn;
    int found = 0, flag = 0, day, fine;
    system("clear");
    cout << "\nBOOK DEPOSIT" << endl;
    cout << "\nEnter Admission num." << endl;
    cin >> sn;
    fp.open("Student.dat", ios::in | ios::out | ios::binary);
    fp1.open("Book.dat", ios::in | ios::out | ios::binary);
    int pos = fp.tellg();
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
                        cout << "\nBook Deposited In No. Of Days?" << endl;
                        cin >> day;
                        if (day > 15)
                        {
                            fine = (day - 15) * 15;
                            cout << "\nFine = " << fine<<" Rs" << endl;
                        }
                        st.resettoken();

                        fp.seekg(pos);
                        fp.write(reinterpret_cast<char *>(&st), sizeof(Student));
                        cout << "\nBook Deposited Successfully" << endl;
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
        pos = fp.tellg();
    }
    if (found == 0)
    {
        cout << "Student Record Not Exist" << endl;
    }
    cin.ignore();
    getch();
    fp.close();
    fp1.close();
}

void start()
{
    system("clear");
    cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "By:\nUmer Farooq and Bilal Ikram" << endl;
    cout << "I22-0518 & I22-1636" << endl;
    getch();
}
void adminmenu()
{
    system("clear");
    int ch2;
    string num;
    cout << "\nADMINISTRATOR MENU" << endl;
    cout << "\n1. CREATE STUDENT RECORD" << endl;
    cout << "2. DISPLAY ALL STUDENT RECORD" << endl;
    cout << "3. DISPLAY SPECIFIC STUDENT RECORD" << endl;
    cout << "4. MODIFY STUDENT RECORD" << endl;
    cout << "5. DELETE STUDENT RECORD" << endl;
    cout << "6. CREATE BOOK" << endl;
    cout << "7. DISPLAY ALL BOOKS" << endl;
    cout << "8. DISPLAY SPECIFIC BOOK" << endl;
    cout << "9. MODIFY BOOK RECORD" << endl;
    cout << "10.DELETE BOOK RECORD" << endl;
    cout << "11.BACK TO MAIN MENU" << endl;
    cout << "\nPLEASE ENTER YOUR CHOICE(1-11)" << endl;
    cin >> ch2;
    switch (ch2)
    {
    case 1:
        writestudent();
        break;
    case 2:
        displayalls();
        
        break;
    case 3:

        system("clear");
        cout << "\nPlease Enter Admission no. ";
        cin >> num;
        displaysps(num);
        break;
    case 4:
        modifystudent();
        break;
    case 5:
        deletestudent();
        break;
    case 6:
        writebook();
        break;
    case 7:
        displayallb();
        break;
    case 8:
    {
        system("clear");
        cout << "\nPlease Enter Book no." << endl;
        cin >> num;
        displayspb(num);
        break;
    }
    case 9:
        modifybook();
        break;
    case 10:
        deletebook();
        break;
    case 11:
        return;
    default:
        cout << "Invalid choice";
    }
    adminmenu();
}
int main()
{

    char ch;
    // start();
    do
    {
        system("clear");
        cout << "\nMAIN MENU" << endl;
        cout << "\n1. BOOK ISSUE" << endl;
        cout << "2. BOOK DEPOSIT" << endl;
        cout << "3. ADMINISTRATOR MENU" << endl;
        cout << "4. EXIT" << endl;
        cout << "\nPLEASE SELECT YOUR OPTION(1-4)" << endl;
        ch = getch();
        // ch = '3';
        switch (ch)
        {
        case '1':
            bookissue();
            break;
        case '2':
            bookdeposit();
            break;
        case '3':
            adminmenu();
            break;
        case '4':
            exit(0);
            break;
        default:
            cout << "INVALID CHOICE";
        }
    } while (ch != 4);
    return 0;
}