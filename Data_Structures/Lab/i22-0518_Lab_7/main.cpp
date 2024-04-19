#include <iostream>
#include <cstring>
#include "Stack.cpp"
using namespace std;
void check(string exp)
{
    Stack s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.Push(exp[i]);
        }

        if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            s.Pop();
        }
    }
    if (s.isEmpty())
        cout << "Congrats. Expression is correct." << endl<<endl;
    
    else
        cout << "Expression is Wrong." << endl<<endl;
}
int main()
{
    Stack s;
    string e1 = "1 + 2 * (3 / 4)";
    string e2 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14";
    string e3 = "1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14";
    check(e1);
    check(e2);
    check(e3);

    // s.display();
    // s.Dequeue();
    // s.PriorityBasedDequeue();       //e1 i.e ID = 0 should be delete
    // cout<<s.FRONT()->st;
    // cout<<s.REAR()->st;
    // s.display();
}
