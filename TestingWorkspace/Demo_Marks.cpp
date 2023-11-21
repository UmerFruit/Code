#include "Headers.h"
using namespace std;
int main()
{
    fstream csv("AMarks.csv", ios::out | ios::app);
    char ch;
    string rollnum,name;
    int marks;
    bool cmt;
    csv<<endl;
    do
    {
        cout<<"Enter name: ";
        cin>>name;
        csv << name << ",";
        cout << "Roll Number: ";
        cin >> rollnum;
        csv << rollnum << ",";

        for (int i = 1; i <= 8; i++)
        {
            cout << "Marks of Q" << i;
            if(i == 4 || i == 3)
                cout<<" (Out of 20)";
            cout<< ": ";
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