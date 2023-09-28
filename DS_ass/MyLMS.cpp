#include "Admin.h"
#include "Student.h"
#include "Librarian.h"
#include "Book.h"
Book bk;    // book class object
Student st; // student class object
Librarian lb;
Admin am;

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
                            cout << "\nFine = " << fine << " Rs" << endl;
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
    cout << "11.CREATE LIBRARIAN" << endl;
    cout << "12.DISPLAY ALL LIBRARIAN" << endl;
    cout << "13.DELETE LIBRARIAN" << endl;
    cout << "14.CREATE ADMIN" << endl;
    cout << "15.DISPLAY ALL ADMIN" << endl;
    cout << "16.DELETE ADMIN" << endl;
    cout << "17.BACK TO MAIN MENU" << endl;
    cout << "\nPLEASE ENTER YOUR CHOICE(1-17)" << endl;
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
        writesLib();
        return;
    case 12:
        displayallL();
        break;
    case 13:
        deletelib();
        break;
    case 14:
    {
        writesadm();
        break;
    }
    case 15:
        displayallA();
        break;
    case 16:
        deleteadm();
        break;
    case 17:
        exit(0);
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
        // ch = getch();
        ch = '3';
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