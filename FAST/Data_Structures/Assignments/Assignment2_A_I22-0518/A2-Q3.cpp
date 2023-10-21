#include <iostream>
#include "Tree.cpp"
using namespace std;
uint64_t gettime()
{
    uint64_t ms = chrono::duration_cast<chrono::nanoseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return ms;
}
void randelement(BSTree<int> &bst, int numElements)
{
    srand(time(0));
    for (int i = 0; i < numElements; i++)
        bst.Insert(rand());
}
uint64_t Searching(BSTree<int> &bst)
{
    uint64_t m1, m2, sum = 0, avg;

    for (int i = 0; i < 100; i++)
    {
        m1 = gettime();
        bst.Search(rand());
        m2 = gettime();
        sum += (m2 - m1);
    }
    avg = sum / 100;
    return avg;
}
void randelement(AVL<int> &avl, int numElements)
{
    srand(time(0));
    for (int i = 0; i < numElements; i++)
        avl.Insert(rand());
}
uint64_t Searching(AVL<int> &avl)
{
    uint64_t m1, m2, sum = 0, avg;

    for (int i = 0; i < 100; i++)
    {
        m1 = gettime();
        avl.Search(rand());
        m2 = gettime();
        sum += (m2 - m1);
    }
    avg = sum / 100;
    return avg;
}
int main()
{
    BSTree<int> bst;
    AVL<int> avl;
    int n = 100000;
    randelement(avl, n);
    randelement(bst, n);

    cout << "\nAvg time to search BST with " << n << " elements = " << Searching(bst) << " Nanoseconds" << endl;
    cout << "\nAvg time to search AVL with " << n << " elements = " << Searching(avl) << " Nanoseconds\n"
         << endl;
    return 0;
}
