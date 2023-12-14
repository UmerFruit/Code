#include "heap.cpp"
using namespace std;
void heapsort(heap &he)
{
    int idx = he.elements;
    int *temp = new int[idx];
    for (int i = 1; i < idx; i++)
    {
        temp[idx - i] = he.remove();
    }
    for (int i = 1; i < idx; i++)
    {
        he.arr[i + 1] = temp[i];
    }
    he.elements = idx;
}

int main()
{
    heap h;
    int arr[10], temp;
    for (int i = 0; i < 10; i++)
    {
        h.insert(i);
        h.print();
    }

    // h.print();
    // heapsort(h);
    // h.print();
}