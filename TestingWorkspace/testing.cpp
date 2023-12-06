#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream fout("acl.txt");
	fout << "Muhammad Jalal Shah <192.168.1.22>\nOmer Khan<192.168.1.24>\nHassan Ali <192.168.1.12>\n";
	fout.close();
	ifstream fin("acl.txt");
	string search;
	if (!fin)
	{
		cout << "Error opening file" << endl;
		return -1;
	}
	cout << "Enter Ip name to search: " << endl;
	cin >> search;
	string name, line;
	int i = 1;
	while (getline(fin, name, '<') && getline(fin, line, '>'))
	{
		if (search == line)
		{
			cout<<"IP found"<<endl;
			cout << name << " " << line << endl;
		}
	}
}
