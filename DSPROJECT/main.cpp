#include "Headers.h"
using namespace std;
int main()
{
    MaxHeap<char> heap(10);
    srand(time(NULL));
    heap.Pop();
    for (int i = 0; i < 10; i++)
    {
        heap.Push(rand() % 26 + 'A');
    }
    heap.display();

    for (int i = 0; i < 10; i++)
    {
        cout << heap.max() << endl;
        heap.Pop();
    }
    return 0;
}
