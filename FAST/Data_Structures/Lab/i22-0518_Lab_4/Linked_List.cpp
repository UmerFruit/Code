#include "Employee.cpp"
class Node
{
public:
    Employee emp;
    Node *next;

    Node(Employee em)
    {
        emp = em;
        next = NULL;
    }
    ~Node()
    {
        next = NULL;
        delete next;
    }
};
class LinkedList
{
private:
    Node *head;
    Node *last;

public:
    LinkedList(int ignore = 0)
    {
        head = NULL;
        last = NULL;
    }
    ~LinkedList()
    {
        head = NULL;
        delete head;
    }
    void insert(Employee emp)
    {
        Node *temp = new Node(emp);
        if (head == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
            last = temp;
        }
    }
    void remove(int id)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        bool exists = false;
        Node *curr = head;
        Node *prev = head;
        while (curr->next != NULL)
        {
            prev = curr;
            if (curr->emp.getid() == id)
            {
                exists = true;
                break;
            }
            curr = curr->next;
            if (curr->emp.getid() == id)
            {
                exists = true;
                break;
            }
        }

        if (exists)
        {
            if (head == curr)
            {
                head = curr->next;
            }
            if (curr->next == NULL)
            {
                last = prev;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        else
        {
            cout << "Record not found :(" << endl;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->emp;
            temp = temp->next;
        }
    }
};