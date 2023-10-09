#include "Headers.h"
using namespace std;
int main()
{
    fstream csv("Marks.csv", ios::out | ios::app);
    char ch;
    string rollnum;
    int marks;
    bool cmt;
    csv<<endl;
    do
    {
        cout << "Roll Number: ";
        cin >> rollnum;
        csv << rollnum << ",";

        for (int i = 1; i <= 15; i++)
        {
            cout << "Marks of Q" << i << ":";
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
