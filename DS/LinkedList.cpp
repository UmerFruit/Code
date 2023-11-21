#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T x;
    Node<T> *next;
    Node(T samaan)
    {
        this->x = samaan;
        next = NULL;
    }
};
template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList(int ignore = 0)
    {
        head = NULL;
    }
    void deleteAll()
    {
        while (head != NULL)
        {
            Node<T> *temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
    }
    int Size()
    {
        int size = 0;
        Node<T> *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            size++;
        }
        return size;
    }
    void insert(T x, int idx)
    {
        Node<T> *temp = new Node<T>(x);
        if (head == NULL)
        {
            head = temp;
        }
        else
        {
            Node<T> *curr = head;
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
    void Delete(T position)
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
            Node<T> *prev = head;
            head = head->next;
            prev->next = NULL;
            delete prev;
            return;
        }
        Node<T> *curr = head;
        Node<T> *prev = NULL;

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
    int find(T data)
    {
        if (head == NULL)
        {
            cout << "EMPTY LIST!" << endl;
            return -1;
        }
        int idx, i = 0;

        bool exists = false;
        Node<T> *curr = head;
        Node<T> *prev = head;
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
            return -1;
        }
    }
    void printList()
    {
        Node<T> *temp = head;
        while (temp != NULL)
        {
            cout << temp->x << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
