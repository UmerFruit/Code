#include <iostream>
using namespace std;
class List
{
private:
    int *arr;
    int size;
    // constructor that initializes the array using DMA
public:
    List(int size)
    {
        while (size < 0)
        {
            cout << "Invalid size" << endl;
            cin >> size;
        }
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }
    }
    void InsertAE(int val)
    {
        int *temp = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        temp[size] = val;
        delete[] arr;
        size++;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
        temp = 0;
    }
    void InsertAS(int val)
    {
        int *temp = new int[size + 1];
        for (int i = 0; i < size; i++)
        {
            temp[i + 1] = arr[i];
        }
        temp[0] = val;
        delete[] arr;
        size++;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
        temp = 0;
    }
    void InsertAI(int idx, int val)
    {
        if (idx >= 0 && idx < size)
        {
            InsertAE(0);
            for (int i = size - 1; i >= idx; i--)
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
            arr[idx] = val;
        }
    }
    void EraseAE()
    {
        int *temp = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        size--;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
        temp = 0;
    }
    void EraseAS()
    {
        int *temp = new int[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            temp[i] = arr[i + 1];
        }
        delete[] arr;
        size--;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = temp[i];
        }
        delete[] temp;
        temp = 0;
    }
    void EraseAI(int idx)
    {
        if (idx >= 0 && idx < size)
        {
            for (int i = 1; i < size - idx; i++)
            {
                int temp = arr[idx + i];
                arr[idx + i] = arr[idx + i - 1];
                arr[idx + i - 1] = temp;
            }
            EraseAE();
        }
    }
    int Next(int idx)
    {
        if (idx == size - 1)
        {
            return idx; // check case
        }
        else
        {
            return arr[idx + 1];
        }
    }
    int Previous(int idx)
    {
        if (idx == 0)
        {
            return idx; // check case
        }
        else
        {
            return arr[idx - 1];
        }
    }
    void Print()
    {
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool is_empty()
    {
        if (size == 0)
        {
            return false;
        }
        for (int i = 0; i < this->size; i++)
        {
            if (arr[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
    void replace(int idx, int val)
    {
        arr[idx] = val;
    }
    void clear()
    {
        if (size == 0)
        {
            cout << "Empty List" << endl;
            return;
        }
        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
    }
    void sort()
    {
        int location = 0;
        int idx = 0;
        for (int i = 0; i < size; i++)
        {
            int min = arr[location];
            bool c = false;
            for (int j = i + 1; j < size; j++)
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
    }
    int Search(int find)
    {
        int start = 0;
        int end = this->size - 1;
        while (start <= end)
        {
            int middle = start + (end - start) / 2;
            if (arr[middle] == find)
            {
                return middle;
            }
            else if (arr[middle] < find)
            {
                start = ++middle;
            }
            else
            {
                end = --middle;
            }
        }
        return -1;
    }
    bool duplicate()
    {
        bool dupli = false;
        for (int i = 0; i < this->size; i++)
        {
            dupli = false;
            for (int j = i + 1; j < this->size; j++)
            {
                if (arr[i] == arr[j])
                {
                    dupli = true;
                }
            }
            if (dupli)
            {
                break;
            }
        }
        return dupli;
    }
};
int main()
{
    // List L(5);
    // L.Print();
    // L.InsertAS(99);
    // L.InsertAS(98);
    // L.InsertAS(97);
    // L.Print();
    // L.InsertAE(10);
    // L.Print();
    // L.InsertAI(1, 15);
    // L.Print();
    // L.EraseAS();
    // L.Print();
    // L.EraseAE();
    // L.Print();
    // L.EraseAI(1);
    // L.Print();
    // cout << L.Next(0) << endl;
    // cout << L.Previous(1) << endl;
    // L.replace(4, 46);
    // L.Print();
    // L.sort();
    // L.Print();
    // cout << L.is_empty() << endl;
    // L.clear();
    // cout << L.is_empty() << endl;
    // cout<<L.Search(99);
    // cout<<L.duplicate();
}