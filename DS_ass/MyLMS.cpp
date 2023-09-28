#include "Headers.h"
void stlogin();
void liblogin();
void adminlogin();
void stmenu(Student &);
void libmenu(Librarian &);
void adminmenu(Admin &);
void start();
void bookdeposit(string);
void bookissue(string);
int main()
{
    char ch;
    // start();
    do
    {
        system("clear");
        cout << "\nMAIN MENU" << endl;
        cout << "1. ADMINISTRATOR LOGIN" << endl;
        cout << "2. LIBRARIAN LOGIN" << endl;
        cout << "3. STUDENT LOGIN" << endl;
        cout << "4. EXIT" << endl;
        cout << "\nPLEASE SELECT YOUR OPTION(1-4)" << endl;
        ch = getch();
        switch (ch)
        {
        case '1':
            adminlogin();
            break;
        case '2':
            liblogin();
            break;
        case '3':
            stlogin();
            break;
        case '4':
            return 0;
            break;
        default:
            cout << "INVALID CHOICE";
        }
    } while (1);
}
void bookissue(string sn)
{
    Book bk;
    Student st;
    fstream fp1, fp;
    string bn;
    int found = 0, flag = 0;
    system("clear");
    cout << "\nBOOK ISSUE" << endl;
    fp.open("Students.dat", ios::in | ios::out | ios::binary);
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
                        bk.showbook();
                        st.addtoken();
                        st.setstbook_num(bk.getbook_num()); // pass book no.
                        fp.seekg(pos);
                        fp.write(reinterpret_cast<char *>(&st), sizeof(Student));
                        cout << "\n\nBook Issued Successfully\n\nPlease Note The Book Issue Date Of Your Book And Return Within 15 Days\nOtherwise Fine = 15 Rs Per Day" << endl;
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
                getch();
                return;
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
void bookdeposit(string sn)
{
    fstream fp, fp1;
    string bn;
    Student st;
    Book bk;
    int found = 0, flag = 0, day, fine;
    system("clear");
    cout << "\nBOOK DEPOSIT" << endl;
    fp.open("Students.dat", ios::in | ios::out | ios::binary);
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
void adminmenu(Admin &a)
{
    system("clear");
    int ch2;
    string num;
    a.adminMenu();
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
        displaysps();
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
        system("clear");
        displayspb();
        break;
    case 9:
        modifybook();
        break;
    case 10:
        deletebook();
        break;
    case 11:
        writesLib();
        break;
    case 12:
        displayallL();
        break;
    case 13:
        deletelib();
        break;
    case 14:
        writesadm();
        break;
    case 15:
        displayallA();
        break;
    case 16:
        deleteadm();
        break;
    case 17:
        return;
    default:
        cout << "Invalid choice";
    }
    adminmenu(a);
}
void libmenu(Librarian &lb)
{
    system("clear");
    int ch2;
    string num;
    lb.libMenu();
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
        modifystudent();
        break;
    case 4:
        deletestudent();
        break;
    case 5:
        writebook();
        break;
    case 6:
        displayallb();
        break;
    case 8:
        modifybook();
        break;
    case 9:
        deletebook();
        break;
    case 10:
        return;
    default:
        cout << "Invalid choice";
    }
    libmenu(lb);
}
void stmenu(Student &st)
{
    system("clear");
    char ch2;
    string num;
    st.studentMenu();
    ch2 = getch();
    switch (ch2)
    {
    case '1':
        bookissue(st.getadm_num());
        break;
    case '2':
        bookdeposit(st.getadm_num());
        break;
    case '3':
        displayallb();
        break;

    case '4':
        displayspb();
        break;
    case '5':
        return;
    default:
        cout << "Invalid choice";
    }
    stmenu(st);
}
void adminlogin()
{
    system("clear");
    Admin a;
    if (a.Check())
        adminmenu(a);
    getch();
}
void liblogin()
{
    system("clear");
    Librarian lb;
    if (lb.Check())
        libmenu(lb);
    getch();
}
void stlogin()
{
    system("clear");
    Student st;
    if (st.Check())
        stmenu(st);
    getch();
}