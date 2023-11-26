#ifndef LIST_H_
#define LIST_H_
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T d)
    {
        data = d;
        next = NULL;
    }
    ~Node()
    {
        next = NULL;
    }
};
template <class T>
class List
{
private:
    Node<T> *head;
    int numelements;

public:
    List()
    {
        numelements = 0;
        head = NULL;
    }
    ~List()
    {
        while (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
    }
    void Push(T in)
    {
        Node<T> *temp = new Node<T>(in);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node<T> *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
        numelements++;
    }
    void Pop()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            delete head;
            head = NULL;
        }
        else
        {
            Node<T> *curr = head;
            while (curr->next->next != NULL)
            {
                curr = curr->next;
            }
            delete curr->next;
            curr->next = NULL;
        }
        numelements--;
    }
    void display()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void clear()
    {
        while (head != NULL)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        delete head;
        head = NULL;
        numelements = 0;
    }
    bool isEmpty()
    {
        return (head == NULL);
    }
    int Size()
    {
        return numelements;
    }
    void Sort()
    {
        if (head == NULL)
        {
            return;
        }
        else if (head->next == NULL)
        {
            return;
        }
        else
        {
            Node<T> *curr = head;
            while (curr != NULL)
            {
                Node<T> *temp = curr->next;
                while (temp != NULL)
                {
                    if (curr->data > temp->data)
                    {
                        T t = curr->data;
                        curr->data = temp->data;
                        temp->data = t;
                    }
                    temp = temp->next;
                }
                curr = curr->next;
            }
        }
    }
};
#endif