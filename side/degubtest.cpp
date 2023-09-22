#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;

void general_function(int, int, int, int, int);

void structure(int, int, int, int);

void making_length(int, int, int, int, int);

void making_height(int, int, int, int, int);

int main()
{
	int height, length, steps, base_pro_max;
    cout << "\nEnter steps: ";
    cin >> steps;
    cout << "\nEnter height: ";
    cin >> height;
    cout << "\nEnter width: ";
    cin >> length;
    base_pro_max = steps * length;
    structure(length, height, steps, base_pro_max);
}

void structure(int length, int height, int steps, int base_pro_max)
{
	int i = 35, counter = 1, num;
	num = (i + steps);
	while(1)
	{
		for (int k=35; k<num; k++)
		{
			i=k;
			for (int j=35; j<num; j++)
			{
                general_function(i, counter, height, length, base_pro_max);
                if(i==(num-1))
                {
                	cout << endl;
                	general_function(i, counter, height, length, base_pro_max);
            	    i=35;
            	    //counter++;
            	    continue;
                }
                i++;
                counter++;
                cout << endl;
                if(j==(num-1))
                {
                	counter=1;
                	for(int o=0; o<base_pro_max; o++)
                	{
                		cout << static_cast<char>(i-1);
					}
					cout<<endl;
					//i=35;
					//continue;
				}
			}
			Sleep(10000);
			system("cls");
		}
	}
}

void general_function(int i, int counter, int height,int length,int base_pro_max)
{
    int a = (length * counter);
	cout << setw(base_pro_max - a); 
	making_length(a, i, base_pro_max, length, height);
}

void making_length(int a, int i, int base_pro_max, int length, int height)
{
    for (int j=1; j<=length; j++)
    {
        cout << static_cast<char>(i);
    }
    cout << endl;
    making_height(a, i, length, height, base_pro_max);
}

void making_height(int a, int i, int length,int height,int base_pro_max)
{
    for (int j=1; j<=height; j++)
    {
        cout << setw(base_pro_max - a) << static_cast<char>(i) << setw(a-1) << static_cast<char>(i);
        cout << endl;
    }
}