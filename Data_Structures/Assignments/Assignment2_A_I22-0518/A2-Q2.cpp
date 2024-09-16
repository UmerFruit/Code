#include <iostream>
#include <cmath>
#include "Stack.cpp"
#include "Queue.cpp"
using namespace std;
float Eval(Queue<string> &postfix)
{
    Stack<float> opndstk;
    /* scan the input string reading one element */
    /* at a time into symb */
    string op;
    float value;
    while (!postfix.isEmpty())
    {
        string symb = postfix.Dequeue();
        if (isdigit(symb[0]))
            opndstk.Push(stoi(symb));
        else
        {
            /* symb is an operator */
            float op2 = opndstk.Pop();
            float op1 = opndstk.Pop();
            switch (symb[0])
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
            }
            opndstk.Push(value);
        } /* end else */
    }     /* end while */
    return (opndstk.Pop());
}
int prec(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return 0;
}
bool isOperator(char c, string &op)
{
    if (c == '+')
    {
        op = "+";
        return true;
    }
    if (c == '-')
    {
        op = "-";
        return true;
    }
    if (c == '*')
    {
        op = "*";
        return true;
    }
    if (c == '/')
    {
        op = "/";
        return true;
    }
    return false;
}
float infixToPostfix(string &Infix)
{
    Stack<string> opstk;
    Queue<string> postfix;
    string op;
    char *symb;
    for (int i = 0; i < Infix.length(); i++)
    {
        symb = &Infix[i];
        if (*symb == ' ')
            continue;
        else if (*symb == '(')
            continue;
        else if (*symb == ')')
            postfix.Enqueue(opstk.Pop());
        else if (isOperator(*symb, op))
            opstk.Push(op);
        else
        {
            int ans = 0;
            while (*symb >= '0' && *symb <= '9')
            {
                ans = (ans * 10) + (*symb - '0');
                symb++;
                i++;
            }
            i--;
            postfix.Enqueue(to_string(ans));
        }
    }
    cout << endl;

    postfix.display();
    cout << endl;
    return Eval(postfix);
}

int main()
{
    cout << "Expression: " << endl;
    string exp;
    getline(cin, exp);
    cout << "Answer is " << infixToPostfix(exp) << endl;
    return 0;
}
