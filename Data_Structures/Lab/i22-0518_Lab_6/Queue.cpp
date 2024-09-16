#include "Student.cpp"
class Node
{
public:
    Student st;
    int Priority;
    Node *next;

    Node(Student &stu, int p) // 1 has the most priority while 5 has the least priority
    {
        st = stu;
        Priority = p;
        next = NULL;
    }
    ~Node()
    {
        next = NULL;
        delete next;
    }
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue(int ignore = 0)
    {
        front = NULL;
        rear = NULL;
    }
    ~Queue()
    {
        while (front)
        {
            Node *temp = front->next;
            delete front;
            front = temp;
        }
    }
    bool isEmpty()
    {
        return (front == NULL);
    }
    void Enqueue(Student &std, int priority) // Assigns least priority if none is given
    {

        Node *temp = new Node(std, priority);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            Node *curr = front;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
            rear = temp;
        }
    }
    void Dequeue()
    {
        if (front == NULL)
        {
            cout << "EMPTY Queue!" << endl;
            return;
        }
        Node *curr = front;
        front = curr->next;
        curr->next = NULL;
        delete curr;
    }
    void PriorityBasedDequeue()
    {
        int minval = 10; // min val means max priority
        if (front == NULL)
        {
            cout << "EMPTY Queue!" << endl;
            return;
        }
        Node *curr = front;
        Node *prev = front;
        Node *maxPnode = front;
        Node *maxNodeprev = front;
        while (curr->next != NULL)
        {
            prev = curr;
            if (curr->Priority < minval)
            {
                minval = curr->Priority;
                maxPnode = curr;
                maxNodeprev = prev;
            }
            curr = curr->next;
            if (curr->Priority < minval)
            {
                minval = curr->Priority;
                maxPnode = curr;
                maxNodeprev = prev;
            }
        }

        if (front == maxPnode)
        {
            front = maxPnode->next;
        }
        if (maxPnode->next == NULL)
        {
            rear = maxNodeprev;
        }
        maxNodeprev->next = maxPnode->next;
        maxPnode->next = NULL;
        delete maxPnode;
    }
    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->st;
            cout << "Priority = " << temp->Priority << endl
                 << endl;
            temp = temp->next;
        }
    }
    Node *FRONT()
    {
        return front;
    }
    Node *REAR()
    {
        return rear;
    }
    void clear()
    {
        while (front)
        {
            Node *temp = front->next;
            delete front;
            front = temp;
        }
    }
};