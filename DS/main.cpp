#include "headers.cpp"
using namespace std;
/*
    har vm ki apni maxheap which sotres theamount of jobs based on priority.
    jobs assign hone k baad vo heap se delete hojayegi.
    assign honay ka matlab hai vo ek "completed" ki queue mai push hojaya gi
    vms in minheap according to perc-used
    queue mai saare jobs read hogaye, phir uske baad vm mai allocate hogaye
    heap bharti jaaye gi vo dequeue hokar
    check if the available comp power is enough to handle the job
    if not spawn new
    if yes then check if perc used is less than 80%
    if yes then allocate
    if no then spawn new
    jese hi uski max jobs hit hogayi
    uski saari jobs write kardo file mai (completed queue mai jo hain),
    har job ki comp req ko nano seconds ke mutabik likhdo, aur vm delete kardo
    jab tak queue mai kuch hai tab tak chalega
*/
int main()
{
    MinHeap min;
    min.insert(30);
    min.insert(10);
    min.insert(20);
    min.insert(20);
    min.insert(10);
    min.insert(20);
    int x = min.size;
    for (int i = 0; i < x; i++)
    {
        min.print();
        min.deleteHeap();
        cout << endl;
    }
}
