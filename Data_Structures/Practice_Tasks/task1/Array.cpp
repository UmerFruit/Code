#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
inline uint64_t gettime()
{
    uint64_t ms = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return ms;
}
class Person
{
private:
    string CNIC;
    string address;
    string name;

public:
    Person()
    {
        address = "Street 16";
        name = "Ahmed Faraz";
    }
    void setcnic(int cnic)
    {
        CNIC = to_string(cnic);
    }
    string getcnic()
    {
        return CNIC;
    }
};
int main()
{
    srand(time(0));
    long long range = 10000000000000;
    const long long S = 100000;
    Person people[S];
    for (int i = 0; i < S; i++)
    {
        people[i].setcnic(rand() % range);
    }
    string findCNIC = to_string(rand() % range);
    
    uint64_t ms = gettime();
    for (int i = 0; i < S; i++)
    {
        if(people[i].getcnic() == findCNIC) //simple linear search approach on array
        {
            cout<<"Found"<<endl;;
            break;
        }
    }
    uint64_t ms2 = gettime();
    cout<<"Diff in time: "<<ms2-ms<<endl;
    return 0;
}