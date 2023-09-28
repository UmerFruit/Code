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
public:
    Node *head;
    int size;

public:
    LinkedList(int ignore = 0)
    {
        size = 0;
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
        size = 0;
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
            size++;
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
            size++;
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
        size--;
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
    void rev(Node *&head, Node *prev, Node *curr)
    {
        if (curr == NULL)
        {
            head = prev;
            return;
        }
        rev(head, curr, curr->next);
        curr->next = prev;
    }
    void rev1(Node *h)
    {
        if (h == NULL || h->next == NULL)
        {
            head = h;
            return;
        }
        rev1(h->next);
        h->next->next = h;
        h->next = NULL;
    }

    Node &operator[](int idx)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return *head;
        }
        bool exists = false;
        Node *curr = head;
        Node *prev = head;
        int i = 0;
        while (i < idx && curr)
        {
            curr = curr->next;
            i++;
        }
        if (curr == NULL)
        {
            cout << "Data not found :(" << endl;
        }
        return *curr;
    }
    void reverse()
    {
        rev1(head);
    }
    Node *swap(Node *ptr1, Node *ptr2)
    {
        Node *tmp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = tmp;
        return ptr2;
    }

    int sort()
    {
        int count = size;
        int i, j, swapped;

        for (i = 0; i < count; i++)
        {
            swapped = 0;

            for (j = 0; j < count - i; j++)
            {

                struct Node *p1 = head;
                struct Node *p2 = p1->next;

                if (p1->x > p2->x)
                {

                    /* update the link after swapping */
                    head = swap(p1, p2);
                    swapped = 1;
                }

                head = head->next;
            }

            /* break if the loop ended without any swap */
            if (swapped == 0)
                break;
        }
    }
};

int main()
{
    srand(time(0));
    LinkedList list;
    for (int i = 0; i < 4; i++)
    {
        list.insert(rand() % 25, i);
    }
    list.printList();
    // cout << list.size << endl;
    // list.reverse();
    list.sort();
    list.printList();
}