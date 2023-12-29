#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
    ifstream fin("rules.txt");
    string data[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
                getline(fin, data[i][j], '\n');
            else
                getline(fin, data[i][j], ' ');
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << data[i][j] << ' ';
        }
        cout << endl;
    }
    string num, apto, ip, deci;
}
void writefile()
{
    ofstream f("rules.txt");
    f << "1 SRC 192.168.1.1 ALLOW" << endl;
    f << "2 DST 192.168.1.1-10 DENY" << endl;
    f << "3 DST 192.168.255.255 ALLOW" << endl;
    f << "4 PRO UDP DENY" << endl;
    f.close();
}