#include<iostream>
using namespace std;

class ItsMagic{
public:
    int* value;

    ItsMagic(int n = 8): value(new int[n - 5] {n})
    {
        for(int i=0; i<n-7; i++)
            *(value + i + 1) = *(value + i) + i + 3;
        cout<<"Hello <:> "<<value[2]<<endl;    
    }

    ItsMagic(const ItsMagic& oh)
    {
        this->value = oh.value + 1;
        *this->value = *oh.value + 5;
        (*this)(oh.value + 1);
        cout<<"Oh Ho <:> "<<value[2]<<endl;  
    }

    int& operator()(int *a)
    {
        *(this->value + 2) = *a++;
        cout<<"Is it you -): "<<*this->value<<endl; 
        return *(this->value + 1);
    }

    void increase(int &n)
    {
        static int N = 5;
        n = N++;
        if(n % 3 == 2)
            this->twice(N);
        cout<<"Seriously -> "<<N<<endl;    
    }

    void twice(int &n)
    {
        static int N = 6;
        n = ++N;
        if(n % 4 == 0)
            this->increase(N);
        cout<<"Please -> "<<N<<endl;
    }

    ~ItsMagic()
    {
        int s = 3;
        cout<<"Don't..... ";
        this->increase(s);
        cout<<s<<endl;
    }

};

class NoWay{
public:
    ItsMagic okay;
    int s;
    NoWay(int a):okay(a)
    {
        s = *okay.value + 3;
        cout<<*(okay.value + 2)<<endl;
        cout<<"Its Okay :) "<<okay(okay.value)<<endl;
    }

    ItsMagic& neverMind()
    {
        okay.increase(s);
        cout<<"Never Mind :( "<<s + okay(okay.value + 1)<<endl;
        return okay;
    }

    ~NoWay()
    {
        int sum = 0;
        cout<<"Are you going ? \n";
        for(int i=0; i<3; i++)
            sum += okay.value[i];
        cout<<"Here take this -> "<<sum<<endl;     
    }

};

void comeHere(ItsMagic boo)
{
    boo(boo.value);
    cout<<"Bye :( "<<*boo.value++<<endl;

}

int main()
{
    ItsMagic isIt;
    NoWay areYou(10);
    comeHere(areYou.neverMind());

}
/*
Hello <:> 0
Hello <:> 17
17
Its Okay :) Is it you -): 10
13
Please -> 7
Seriously -> 7
Never Mind :( Is it you -): 10
18
Is it you -): 15
Oh Ho <:> 15
Is it you -): 15
Bye :( 15
Don't.....Seriously -> 8
7
Are you going ? 
Here take this -> 38
Don't.....Please -> 9
Seriously -> 9
8
*/