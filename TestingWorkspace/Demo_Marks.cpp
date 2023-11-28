#include "Headers.h"
using namespace std;
void ass5(string section)
{
    fstream csv(section + "Marks5.csv", ios::out | ios::app);
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
            if (i == 3 || i == 4)
            {
                int m = marks;
                cin>>marks;
                m += marks;
                marks = m;
            }
            
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
    csv.close();
}

int main()
{
    string section;
    char cont;
    do
    {
        ass5("A");
        cout << "exit? (y/n)" << endl;
        cin >> cont;
    } while (cont == 'n');
    return 0;
}