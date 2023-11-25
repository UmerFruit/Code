#include "Headers.h"
using namespace std;
void Bass5()
{
    fstream csv("BMarks5.csv", ios::out | ios::app);
    char ch;
    string rollnum, name;
    int marks;
    bool cmt;
    csv << endl;
    do
    {
        cout << "Enter name: ";
        cin >> name;
        csv << name << ",";
        cout << "Roll Number: ";
        cin >> rollnum;
        csv << rollnum << ",";

        for (int i = 1; i <= 8; i++)
        {
            cout << "Marks of Q" << i;
            if (i == 4 || i == 3)
                cout << " (Out of 20)";
            cout << ": ";
            cin >> marks;
            csv << marks;
            csv << ',';
        }
        cout << "Enter Comment(0/1)";
        cin >> cmt;
        if (cmt)
        {
            string com;
            cin.ignore();
            getline(cin, com);
            csv << com;
        }
        csv << endl;
        cout << "Add new Record? (y/n)" << endl;
        cin >> ch;
    } while (ch != 'n');
}
void Bass6()
{
    fstream csv("BMarks6.csv", ios::out | ios::app);
    char ch;
    string rollnum, name;
    int marks;
    bool cmt;
    csv << endl;
    do
    {
        cout << "Enter name: ";
        cin >> name;
        csv << name << ",";
        cout << "Roll Number: ";
        cin >> rollnum;
        csv << rollnum << ",";

        for (int i = 1; i <= 4; i++)
        {
            cout << "Marks of Q" << i;
            cout << "(out of 25)";
            cout << ": ";
            cin >> marks;
            csv << marks;
            csv << ',';
        }
        cout << "Enter Comment(0/1)";
        cin >> cmt;
        if (cmt)
        {
            string com;
            cin.ignore();
            getline(cin, com);
            csv << com;
        }
        csv << endl;
        cout << "Add new Record? (y/n)" << endl;
        cin >> ch;
    } while (ch != 'n');
}
void Aass5()
{
    fstream csv("AMarks5.csv", ios::out | ios::app);
    char ch;
    string rollnum, name;
    int marks;
    bool cmt;
    csv << endl;
    do
    {
        cout << "Enter name: ";
        cin >> name;
        csv << name << ",";
        cout << "Roll Number: ";
        cin >> rollnum;
        csv << rollnum << ",";

        for (int i = 1; i <= 8; i++)
        {
            cout << "Marks of Q" << i;
            if (i == 4 || i == 3)
                cout << " (Out of 20)";
            cout << ": ";
            cin >> marks;
            csv << marks;
            csv << ',';
        }
        cout << "Enter Comment(0/1)";
        cin >> cmt;
        if (cmt)
        {
            string com;
            cin.ignore();
            getline(cin, com);
            csv << com;
        }
        csv << endl;
        cout << "Add new Record? (y/n)" << endl;
        cin >> ch;
    } while (ch != 'n');
}
void Aass6()
{
    fstream csv("AMarks6.csv", ios::out | ios::app);
    char ch;
    string rollnum, name;
    int marks;
    bool cmt;
    csv << endl;
    do
    {
        cout << "Enter name: ";
        cin >> name;
        csv << name << ",";
        cout << "Roll Number: ";
        cin >> rollnum;
        csv << rollnum << ",";

        for (int i = 1; i <= 4; i++)
        {
            cout << "Marks of Q" << i;
            cout << "(out of 25)";
            cout << ": ";
            cin >> marks;
            csv << marks;
            csv << ',';
        }
        cout << "Enter Comment(0/1)";
        cin >> cmt;
        if (cmt)
        {
            string com;
            cin.ignore();
            getline(cin, com);
            csv << com;
        }
        csv << endl;
        cout << "Add new Record? (y/n)" << endl;
        cin >> ch;
    } while (ch != 'n');
}
void Asec()
{
    char c;
    char cont;
    do
    {
        cout << "Assignment number: ";
        cin >> c;

        if (c == '5')
        {
            Aass5();
        }
        if (c == '6')
        {
            Aass6();
        }
        cout << "new assignment? (y/n)" << endl;
        cin >> cont;
    } while (cont == 'y');
}
void Bsec()
{
    char cont;
    char c;
    do
    {
        cout << "Assignment number: ";
        cin >> c;

        if (c == '5')
        {
            Bass5();
        }
        if (c == '6')
        {
            Bass6();
        }
        cout << "new assignment? (y/n)" << endl;
        cin >> cont;
    } while (cont == 'y');

}

int main()
{
    char sec;
    char cont;

    do
    {
        cout << "Section? (A/B)";
        cin >> sec;
        if(sec == 'A' || sec == 'a')
        {
            Asec();
        }
        if (sec == 'B' || sec == 'b')
        {
           Bsec();
        }
        cout << "Section Change? (y/n)" << endl;
        cin>>cont;
    } while (cont == 'y');
    return 0;
}