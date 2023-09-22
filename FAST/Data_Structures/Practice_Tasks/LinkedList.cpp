#include <iostream>
using namespace std;
class Node
{
public:
    int x;
    Node *next;
    Node(int samaan)
    {
        this->x = samaan;
        next = NULL;
    }
};
class LinkedList
{
private:
    Node *head;

public:
    LinkedList(int ignore = 0)
    {
        head = NULL;
    }
    void deleteAll()
    {
        while (head != NULL)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
    }
    int Size()
    {
        int size = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            size++;
        }
        return size;
    }
    void insert(int x, int idx)
    {
        Node *temp = new Node(x);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node *curr = head;
            int i = 1;
            while (curr != NULL)
            {
                if (i >= idx)
                {
                    break;
                }
                curr = curr->next;
                i++;
                if (i >= idx)
                {
                    break;
                }
            }
            if (!curr)
            {
                cout << "Index not found" << endl;
                return;
            }
            if (idx == 0)
            {
                temp->next = head;
                head = temp;
                return;
            }
            temp->next = curr->next;
            curr->next = temp;
        }
    }
    void Delete(int position)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return;
        }
        else if (position < 0 || position > Size())
        {
            cout << "Index not found" << endl;
            return;
        }
        if (position == 1)
        {
            Node *prev = head;
            head = head->next;
            prev->next = NULL;
            delete prev;
            return;
        }
        Node *curr = head;
        Node *prev = NULL;

        int i = 1;
        while (i < position)
        {
            prev = curr;
            curr = curr->next;
            i++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
    int find(int data)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return -1;
        }
        int idx, i = 0;

        bool exists = false;
        Node *curr = head;
        Node *prev = head;
        while (curr->next != NULL)
        {
            prev = curr;
            if (curr->x == data)
            {
                idx = i;
                exists = true;
                break;
            }
            curr = curr->next;
            i++;
            if (curr->x == data)
            {
                idx = i;
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
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
            return idx;
        }
        else
        {
            cout << "Data not found :(" << endl;
            return -1;
        }
    }
    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->x << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    list.insert(5, 0);
    list.printList();
    list.insert(6, 0);
    list.printList();
    list.insert(7, 2);
    list.printList();
    list.insert(8, 2);
    list.printList();
    list.insert(9, 2);
    list.printList();
    list.Delete(2);
    list.printList();
    cout<<list.find(23);
}