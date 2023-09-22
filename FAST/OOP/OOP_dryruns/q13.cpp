//---------------------Question # 13---------------------//
#include <iostream>
using namespace std;
class M
{
public:

    virtual void myMemory()
    {
        cout<<"I forget ";
    }
    void Disk()
    {
        cout<<"Space ";
    }
    void Erased()
    {
        cout<<"For good ";
    }
    void thisExam()
    {
        Erased(); myMemory();
    }
    virtual ~M() {}

};

class N: public M
{
public:
    void myMemory()
    {
        cout<<"Gone ";
    }
    void Disk()
    {
        cout<<"Slipped ";
    }

    void virtual Erased()
    {
        cout<<"Rubbed out ";
    }
};

int main()
{
    M *m1 = new N;
    m1->myMemory();
    m1->Disk();
    m1->thisExam();

    M m2 = *(new N);
    m2.myMemory();
    m2.Disk();
    m2.thisExam();

}
/*
Gone Slipped For good Gone I forget Space For good I forget 

*/