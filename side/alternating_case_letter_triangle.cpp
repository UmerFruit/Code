#include <iostream>
using namespace std;
int main() 
{
	int end=1,c=1;
	char ch='a';

	for (int i = 0; i < 5; i++)
	{
		for (int i = 1; i <= end; i++)
		{
			
			cout<<ch;
			if(c%2)
			{
				ch = (ch+1)-32;
			}
			else
			{
				ch = (ch+1)+32;
			}
			c++;
		}
		
		end += 1;
		cout<<endl;
	}
}