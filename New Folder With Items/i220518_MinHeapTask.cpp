#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
class heap
{
public:
    int *arr;
    int elements;

    heap(int capacity = 100)
    {
        arr = new int[capacity];
        arr[0] = -1; // 1 based indexing
        elements = 0;
    }
    void insert(int val)
    {
        elements++;
        int idx = elements;
        arr[idx] = val;
        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[parent] > arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }
            else
                return;
        }
    }
    void deleteMin()
    {
        if (elements == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }
        arr[1] = arr[elements];
        elements--;
        int i = 1;
        while (i < elements)
        {
            int right = 2 * i + 1;
            int left = 2 * i;

            if (left < elements && arr[i] > arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }
            else if (right < elements && arr[i] > arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
            {
                return;
            }
        }
    }
    ~heap()
    {
        delete[] arr;
    }
    void print()
    {
        for (int i = 1; i <= elements; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

bool isMinheap(int arr[], int size, int idx = 1)
{
    if (idx > size)
    {
        return true;
    }

    int left = idx * 2;
    int right = idx * 2 + 1;

    if (left <= size && arr[idx] > arr[left])
    {
        return false;
    }
    else if (right <= size && arr[idx] > arr[right])
    {
        return false;
    }

    return isMinheap(arr, size, left) && isMinheap(arr, size, right);
}
pair<bool,int*> Minheap(string filename, int size)
{
    ifstream fin(filename);
    int *arr = new int[size];
    int i = 1;
    while (!fin.eof())
    {
        fin >> arr[i++];
    }
    return make_pair(isMinheap(arr, size), arr);
}
int main()
{
    ifstream fin("notminheap.txt");
    heap h;
    int temp;
    while (!fin.eof())
    {
        fin >> temp;
        h.insert(temp);
    }
    int val = 1;
    cout << "Valid min Heap before insertion of " << val<<endl;
    h.print();

    h.insert(val);

    cout << "Valid min Heap after insertion of " << val<<endl;
    h.print();

    h.deleteMin();
    
    cout << "Valid min Heap before deletion of min element\n";
    h.print();

    h.deleteMin();

    cout << "Valid min Heap after deletion of min element\n";
    h.print();
    cout<<endl;
    int size = 10;

    pair<bool, int *> f1 = Minheap("notminheap.txt", size); //or notminheap.txt
    for (int i = 1; i <= 10; i++)
    {
        cout << f1.second[i] << " ";
    }
    if (f1.first)
    {
        cout << "\nIs a min heap\n";
    }
    else
    {
        cout << "\nIs not a min heap\n";
    }
}
