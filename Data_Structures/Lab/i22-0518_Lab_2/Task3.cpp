#include <iostream>
using namespace std;
int main()
{
    int arr[10] = {8, 4, 2, 1, 6, 9, 7, 3, 5, 0};
    int location = 0;
    int idx = 0;

    for (int i = 0; i < 10; i++)
    {
        int min = arr[location];
        bool c = false;
        for (int j = i + 1; j < 10; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                idx = j;
                c = true;
            }
        }
        if (c)
        {
            int temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
        location = i + 1;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}