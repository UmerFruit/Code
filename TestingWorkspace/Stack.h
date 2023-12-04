#ifndef STACK_H_
#define STACK_H_
using namespace std;
template <class T>
class StackNode
{
public:
    T element;
    StackNode<T> *next;

    StackNode(T c)
    {
        element = c;
        next = NULL;
    }
    ~StackNode()
    {
        next = NULL;
    }
};
template <class T>
class Stack
{
private:
    StackNode<T> *top;
    int Size;
    int numElements;

public:
    Stack(int s = 10)
    {
        top = NULL;
        Size = s;
        numElements = 0;
    }
    ~Stack()
    {
        while (top)
        {
            StackNode<T> *temp = top->next;
            delete top;
            top = temp;
        }
    }
    bool isFull()
    {
        return (numElements == Size);
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void Push(T element)
    {
        if (numElements + 1 > Size)
        {
            cout << "Stack Full" << endl;
            return;
        }

        StackNode<T> *temp = new StackNode<T>(element);
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
    void Pop()
    {
        if (top == NULL)
        {
            cout << "EMPTY Stack!" << endl;
            return;
        }
        StackNode<T> *temp = top;
        top = top->next;
        temp->next = NULL;
        delete temp;
        numElements--;
    }
    void display()
    {
        if (!top)
        {
            cout << "Empty Stack not print" << endl;
            return;
        }
        for (StackNode<T> *temp = top; temp != NULL; temp = temp->next)
            cout << temp->element << " ";
        cout << endl;
    }
    T Top()
    {
        return top->element;
    }
    int size()
    {
        return numElements;
    }
    void Clear()
    {
        while (top)
        {
            StackNode<T> *temp = top->next;
            delete top;
            top = temp;
        }
        numElements = 0;
    }
};
#endif