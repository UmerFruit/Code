#include <iostream>
#include "Queue.cpp"
using namespace std;
int main()
{
    Student e1;
    Student e2("9", "Humayun", 2.9, 5);
    Student e3("8", "Ali Faraz", 2.8, 20);
    Student e4("7", "shahbaz", 2.7, 5);
    Student e5("6", "haseeb", 2.6, 20);
    Student e6("5", "bilal", 2.5, 5);
    Student e7("4", "saad", 2.4, 20);
    Student e8("3", "ahmed", 2.3, 20);
    Student e9("2", "shafqat", 2.2, 5);
    Student e10("1", "jalal", 2.1, 20);

    Queue q;
    q.Enqueue(e1, 3);
    q.Enqueue(e2, 1);
    q.Enqueue(e3, 3);
    q.Enqueue(e4, 2);
    q.Enqueue(e5, 2);
    q.Enqueue(e6, 4);
    q.Enqueue(e7, 2);
    q.Enqueue(e8, 2);
    q.Enqueue(e9, 3);
    q.Enqueue(e10, 4);
    // q.display();
    // q.Dequeue();
    // q.PriorityBasedDequeue();       //e1 i.e ID = 0 should be delete
    // cout<<q.FRONT()->st;
    // cout<<q.REAR()->st;
    // q.display();
}
