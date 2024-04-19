#include <iostream>
#include <cmath>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;
// Q1 part a
int binaryToDecimal(long long binary)
{
    int decimal = 0;
    Stack<int> binaryStack, temp;
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
// Q1 part b
long long decimalToBinary(int decimal)
{
    Stack<int> binaryStack, temp;

    if (decimal == 0)
    {
        return 0;
    }
    while (decimal > 0)
    {
        temp.Push(decimal % 2);
        decimal /= 2;
    }
    while (!temp.isEmpty())
        binaryStack.Push(temp.Pop());

    long long binary = 0;
    int position = 0;
    while (!binaryStack.isEmpty())
    {
        binary += pow(10, position) * binaryStack.Pop();

        position++;
    }
    return binary;
}
// Q1 part c
float postfixEval(string expression)
{
    Stack<float> opndstk;
    /* scan the input string reading one element */
    /* at a time into symb */
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char symb = expression[i];
        if (symb == ' ')
            continue;
        if (isdigit(symb))
        {
            opndstk.Push(symb - '0');
        }
        else
        {

            /* symb is an operator */
            float op2 = opndstk.Pop();
            float op1 = opndstk.Pop();
            float value;
            switch (symb)
            {
            case '*':
                value = op1 * op2;
                break;
            case '+':
                value = op1 + op2;
                break;

            case '-':
                value = op1 - op2;
                break;

            case '/':
                value = op1 / op2;
                break;

            case '^':
                value = pow(op1, op2);
                break;
            }
            opndstk.Push(value);
        }
    }
    return (opndstk.Pop());
}
void parta()
{
    long long binary;
    cout << "Enter a Binary number: ";
    cin >> binary;
    cin.ignore();

    int decimal = binaryToDecimal(binary);
    cout << "Binary equivalent: " << decimal << endl;
}
void partb()
{
    int Decimal;
    cout << "Enter a Decimal number: ";
    cin >> Decimal;
    cin.ignore();

    int Binary = decimalToBinary(Decimal);
    cout << "Binary equivalent: " << Binary << endl;
}
void partc()
{
    cout << "Expression: " << endl;
    string ex;
    getline(cin, ex);
    cout << "Answer is " << postfixEval(ex) << endl;
}
int main()
{
    
    partc();

    return 0;
}
