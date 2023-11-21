using namespace std;
template <class T>
class QueueNode
{
public:
    T data;
    QueueNode<T> *next;

    QueueNode(T d) // 1 has the most priority while 5 has the least priority
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

public:
    Queue()
    {
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
    bool isEmpty()
    {
        return (front == NULL);
    }
    void Enqueue(T data) // Assigns least priority if none is given
    {

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
    T Dequeue()
    {
        if (front == NULL)
        {
            cout << "EMPTY Queue!" << endl;
            return 0;
        }
        QueueNode<T> *curr = front;
        T element = curr->data;
        front = curr->next;
        curr->next = NULL;
        delete curr;
        return element;
    }

    void display()
    {
        
        QueueNode<T> *temp = front;
        if(!temp)
        {
            cout<<"Empty Queue not print"<<endl;
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
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
    }
};