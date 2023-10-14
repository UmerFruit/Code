#include "Headers.h"
#include <queue>
void part1(string name);
void part2(string name);
void part3(string name);
int main()
{
    cout << "\ta" << endl;
    cout << "        a" << endl;
}
void part3(string name)
{
    queue<char> q;
    for (int i = 0; i < name.length(); i++)
    {
        q.push(name[i]);
    }
}
void part2(string name)
{
    string temp;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 1; i <= 26; i++)
        {
            temp = name;
            for (int z = 0; z < temp.length(); z++)
            {
                temp[z] += rand() % i;
            }
            cout << temp << flush << '\r';
            usleep(60000);
        }
    }
    cout << name;
}

void part1(string name)
{
}