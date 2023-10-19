#include <iostream>
#include <cmath>
using namespace std;
class Node
{
public:
    int element;
    Node *next;

    Node(int c)
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
    int Pop()
    {
        if (top == NULL)
        {
            cout << "EMPTY Stack!" << endl;
            return '\0';
        }
        Node *temp = top;
        top = top->next;
        temp->next = NULL;
        int el = temp->element;
        delete temp;
        numElements--;
        return el;
    }
    void PrintStack()
    {
        for (Node *temp = top; temp != NULL; temp = temp->next)
        {
            cout << temp->element << endl;
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
int binaryToDecimal(long long binary)
{
    int decimal = 0;
    Stack binaryStack, temp;
    string n = to_string(binary);
    int numdigs = n.size();
    for (int i = 0; i < numdigs; i++)
    {
        temp.Push(binary % 10);
        binary /= 10;
    }
    while (!temp.isEmpty())
        binaryStack.Push(temp.Pop());
    int position = 0;
    while (!binaryStack.isEmpty())
    {
        decimal += binaryStack.Pop() * pow(2, position);
        position++;
    }
    return decimal;
}
long long decimalToBinary(int decimal)
{
    Stack binaryStack,temp;

    if (decimal == 0)
    {
        return 0;
    }
    while(decimal>0)
    {
        temp.Push(decimal % 2);
        decimal /= 2;
    }
    while (!temp.isEmpty())
        binaryStack.Push(temp.Pop());
    
    long long binary=0;
    int position = 0;
    while (!binaryStack.isEmpty())
    {
        binary += pow(10,position)*binaryStack.Pop();
        
        position++;
    }
    return binary;
}

int main()
{
    long long binary;

    cout << "Enter a Decimal number: ";
    cin >> binary;

    int decimal = decimalToBinary(binary);

    cout << "Binary equivalent: " << decimal << endl;

    return 0;
}
