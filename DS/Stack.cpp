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
    int size;
    int numElements;

public:
    Stack()
    {
        top = NULL;
        size = 10;
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
        return (numElements == size);
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void Push(T element)
    {
        if (numElements + 1 > size)
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
    T Pop()
    {
        if (top == NULL)
        {
            cout << "EMPTY Stack!" << endl;
            return 0;
        }
        StackNode<T> *temp = top;
        top = top->next;
        temp->next = NULL;
        T el = temp->element;
        delete temp;
        numElements--;
        return el;
    }
    void PrintStack()
    {
        if (!top)
        {
            cout << "Empty Stack not print" << endl;
            return;
        }
        for (StackNode<T> *temp = top; temp != NULL; temp = temp->next)
            cout << temp->element << endl;
    }
    T Peak()
    {
        return top->element;
    }
    void Clear()
    {
        while (top)
        {
            StackNode<T> *temp = top->next;
            delete top;
            top = temp;
        }
    }
};