//---------------------Question # 6---------------------//
#include <iostream>
using namespace std;
class Yes
{
public:
    Yes() { cout << " Yes() "; }
};

class No
{
    Yes y;
public:
    No() { cout << " No() "; }
};

class Emotion{
    public :
        Emotion()
        {
            cout << "Emotion() ";
        }
};

class Sad : public Emotion
{
    No n;

public:
    Sad() { cout << "Sad() "; }
};

class Depress : public Sad
{
    public :
        Depress(){cout << " Depress() ";}
};

int main()
{
    Depress why;
    cout << "\nOH No! :( \n";
    cout << "OH Yeah! ): \n";
    Sad noWay;
}
/*
Emotion() Yes() No() Sad() Depress() 
OH No! :( 
OH Yeah! ):
Emotion() Yes() No() Sad() 
*/