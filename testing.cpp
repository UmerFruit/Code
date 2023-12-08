// #include "Headers.h"
// using namespace std;
// int f(vector<int> arr, int size)
// {
// 	// print arr
// 	for (int i = 0; i < size; i++)
// 	{
// 		cout << arr[i] << " ";
// 	}
// 	cout << endl;
// }
// int main()
// {
// 	vector<int> v;
// 	v.assign({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
// 	f(v, 2);
// }

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;

	// Initialize v with an initialization list
	v.assign({0,7,1, 2, 3, 4, 5});
	cout<<"RETURNED "<<*find(v.begin(),v.end(),0)<<endl;
	if(find(v.begin(), v.end(), 0) != v.end())
	{
		cout << "Found" << endl;
	}
	else
	{
		cout << "Not Found" << endl;
	}
	return 0;
}
