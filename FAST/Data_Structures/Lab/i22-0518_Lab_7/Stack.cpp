#include <iostream>
using namespace std;
class Node
{
public:
    char element;
    Node *next;

    Node(char c)
    {
        element = c;
        next = NULL;
    }
    ~Node()
    {
        next = NULL;
        delete next;
    }
};
class Stack
{
private:
    Node *top;
    int size;
    int numElements;

public:
    Stack(int ignore = 0)
    {
        top = NULL;
        size = 10;
        numElements = 0;
    }
    ~Stack()
    {
        while (top)
        {
            Node *temp = top->next;
            delete top;
            top = temp;
        }
    }
    bool isFull()
    {
        return (numElements == size);
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void Push(char element)
    {
        if (numElements + 1 > size)
        {
            cout << "Stack Full" << endl;
            return;
        }

        Node *temp = new Node(element);
        if (top == NULL)
        {
            top = temp;
        }
        else
        {
            temp->next = top;
            top = temp;
        }
        numElements++;
    }
    char Pop()
    {
        if (top == NULL)
        {
            cout << "EMPTY Stack!" << endl;
            return '\0';
        }
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        char el = temp->element;
        delete temp;
        numElements--;
        return el;
    }
    void PrintStack()
    {
        for (Node *temp = top; temp != NULL; temp = temp->next)
        {
            cout << temp->element << endl;
            temp = temp->next;
        }
    }
    char Peak()
    {
        return top->element;
    }
    void Clear()
    {
        while (top)
        {
            Node *temp = top->next;
            delete top;
            top = temp;
        }
    }
};