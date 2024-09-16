// 22i-0518_Lab1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
#include <iostream>
using namespace std;


template <typename T1>
void print(T1 Arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i]<<" ";
    }
}
template <typename T2>

void inter(T2 a[], T2 b[], int sizea, int sizeb)
{
    
    for (int i = 0; i < sizea; i++)
    {
        for (int j = 0; j < sizeb; j++)
        {
            if (a[i] == b[j])
            {
                cout << a[i] << " ";
            }
        }
        
    }
}
template <typename T3>
void uni(T3 a[], T3 b[], int sizea, int sizeb)
{
    int size = sizea + sizeb;
    T3* u = new T3[size];
    int k = 0;
    for (int i = 0; i < sizea; i++)
    {
        u[k] = a[i];
        k++;
    }

    for (int j = 0; j < sizeb; j++)
    {
        u[k] = b[j];
        k++;
    }
    for (int i = 0; i < size; i++)
    {
        bool c = true;
        for (int j = i+1; j < size; j++)
        {
            if (u[i] == u[j])
            {
                c = false;
            }
        }
        if (c)
        {
            cout << u[i]<<" ";
        }
    }

}
template <typename T4>
bool disjoint(T4 a[], T4 b[], int sizea, int sizeb)
{
    for (int i = 0; i < sizea; i++)
    {
        for (int j = 0; j < sizeb; j++)
        {
            if (a[i] == b[j])
            {
                return true;
            }
        }

    }
    return false;
}
template <typename T5>

bool find(T5 a[], int sizea, T5 find)
{
    for (int j = 0; j < sizea; j++)
    {
        if (find == a[j])
        {
            return true;
        }
    }
    return false;
}

int main()                                      //QUESTION 1
{
    double A[] = {10.43,4.3,5.61,6.90,11.57,12.11,3.8,2.4,9.5};
    int sizeA = 9;
    double B[] = {11.01,12.34,16.5,3.8,8.1,2.4,9.11,12.11,6.75,10.43,20.2,2.1,4.3};
    int sizeB = 13;
    //print<double>(A, sizeA);
    cout << endl;
    //print<double>(B, sizeB);
    cout << endl;
    //inter<double>(A, B,sizeA,sizeB);
    uni<double>(A, B, sizeA, sizeB);
    
}

*/

/*
#include <iostream>
#include <string>
using namespace std;
template <typename T,typename U>
class Numbers {
private:
    T A;
    U B;
public:
    Numbers(T A1, U B1)
    {
        A = A1;
        B = B1;
    }
    T Asquare()
    {
        T result = A * A;
        return result;
    }
    T division()
    {
        if (B != 0)
            return A / B;
        else
            return 0;
    }
};
int main()                  //QUESTION 2
{
    Numbers<float,int> num(10.9, 3);
    cout << " A square : " << num.Asquare() << endl;
    cout << " A/B : " << num.division() << endl;
}
*/

