#include <iostream>
#include <vector>
using namespace std;

class heap
{
public:
    vector<pair<int, int>> arr;
    int capacity;
    int elements;

    heap(int capacity = 100)
    {
        this->capacity = capacity;
        arr.resize(capacity);
        arr[0] = {-1, -1}; // 1 based indexing
        elements = 0;
    }
    void insert(pair<int, int> val)
    {
        int index = ++elements;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent].second > arr[index].second)
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void heapify(vector<pair<int, int>> arr, int n, int i)
    {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[smallest].second > arr[left].second)
        {
            smallest = left;
        }

        if (right < n && arr[smallest].second > arr[right].second)
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(arr, n, smallest);
        }
    }
    void deleteentry(pair<int, int> find)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].first == find.first)
            {
                arr.erase(arr.begin() + i);
            }
        }
        // int n = arr.size();

        // for (int i = (n / 2) - 1; i >= 0; i--)
        // {
        //     heapify(arr, n, i);
        // }
        elements--;
    }
    pair<int, int> getmin()
    {
        return arr[1];
    }
    void deletemin()
    {
        if (elements == 0)
        {
            cout << "Heap is empty." << endl;
            return;
        }
        arr[1] = arr[elements];
        elements--;
        int idx = 1;
        while (idx < elements)
        {
            int left = 2 * idx;
            int right = 2 * idx + 1;
            if (left > elements)
                return;
            if (right > elements)
            {
                if (arr[left].second < arr[idx].second)
                {
                    swap(arr[left], arr[idx]);
                    idx = left;
                }
                else
                    return;
            }
            else
            {
                if (arr[left].second < arr[right].second)
                {
                    if (arr[left].second < arr[idx].second)
                    {
                        swap(arr[left], arr[idx]);
                        idx = left;
                    }
                    else
                        return;
                }
                else
                {
                    if (arr[right].second < arr[idx].second)
                    {
                        swap(arr[right], arr[idx]);
                        idx = right;
                    }
                    else
                        return;
                }
            }
        }
    }
    bool isEmpty()
    {
        return elements == 0;
    }
    void clear()
    {
        arr.clear();
        elements = 0;
        arr.resize(capacity);
    }
    ~heap()
    {
        arr.clear();
    }
    void print()
    {
        for (int i = 1; i <= elements; i++)
        {
            cout << " (" << arr[i].first << "," << arr[i].second << ") ";
        }
        cout << endl;
    }
};
