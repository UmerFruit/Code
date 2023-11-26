#ifndef QUEUE_H
#define QUEUE_H

using namespace std;
template <class T>
class QueueNode
{
public:
    T data;
    QueueNode<T> *next;

    QueueNode(T d)
    {
        data = d;
        next = NULL;
    }
};
template <class T>
class Queue
{
private:
    QueueNode<T> *front;
    QueueNode<T> *rear;
    int numelements;

public:
    Queue()
    {
        numelements = 0;
        front = NULL;
        rear = NULL;
    }
    ~Queue()
    {
        while (front)
        {
            QueueNode<T> *temp = front->next;
            delete front;
            front = temp;
        }
    }
    int size()
    {
        return numelements;
    }
    bool isEmpty()
    {
        return (front == NULL);
    }
    void Enqueue(T data) // Assigns least priority if none is given
    {
        numelements++;
        QueueNode<T> *temp = new QueueNode<T>(data);
        if (front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            QueueNode<T> *curr = front;
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
        QueueNode<T> *curr = front;
        front = curr->next;
        curr->next = NULL;
        delete curr;
        numelements++;
    }

    void display()
    {

        QueueNode<T> *temp = front;
        if (!temp)
        {
            cout << "Empty Queue not print" << endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    T FRONT()
    {
        return front->data;
    }
    T REAR()
    {
        return rear->data;
    }
    void clear()
    {
        while (front)
        {
            QueueNode<T> *temp = front->next;
            delete front;
            front = temp;
        }
        numelements = 0;
    }
};
#endif