#include <iostream>
#include <cmath>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;
//Q1 part 1
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
//Q1 part 2
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
//Q1 part 3
int postfixEval(string expression)
{
    Stack<int> opndstk;
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
            int op2 = opndstk.Pop();
            int op1 = opndstk.Pop();
            int value;
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

int main()
{
    // cout << "Expression: " << endl;
    // string ex;
    // getline(cin, ex);
    // cout<<"Answer is "<<postfixEval(ex)<<endl;
    // long long binary;
    // cout << "Enter a Decimal number: ";
    // cin >> binary;
    // int decimal = binaryToDecimal(binary);
    // cout << "Binary equivalent: " << decimal << endl;
    return 0;
}
