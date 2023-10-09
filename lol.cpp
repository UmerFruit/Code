#include "Headers.h"

using namespace std;
int PC1[8][7] =
    {
        {57, 49, 41, 33, 25, 17, 9},
        {1, 58, 50, 42, 34, 26, 18},
        {10, 2, 59, 51, 43, 35, 27},
        {19, 11, 3, 60, 52, 44, 36},
        {63, 55, 47, 39, 31, 23, 15},
        {7, 62, 54, 46, 38, 30, 22},
        {14, 6, 61, 53, 45, 37, 29},
        {21, 13, 5, 28, 20, 12, 4}};

int main()
{
    int original[8][8]; // Your original array
    int c = 1;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            original[i][j]= c;
            c++;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout<<setw(3)<<original[i][j]<<" ";
        }
        cout << endl;
    }
    

    return 0;
}
