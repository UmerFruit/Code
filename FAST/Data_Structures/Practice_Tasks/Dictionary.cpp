#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
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
    char firstDigit()
    {
        return CNIC[0];
    }
};
bool searching(long long *arrays, long long CNIC, long long S)
{
    for (int i = 0; i < S; i++)
    {
        if (CNIC == arrays[i])      //searches the array for the cnic
        {
            return true;
        }
    }
    return false;
}
inline uint64_t gettime() //function returns time in microseconds
{
    uint64_t ms = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return ms;
}
long long **dictionary(Person *people, long long S)
{
    long long **arrays = new long long *[10];
    for (int i = 0; i < 10; i++)
    {
        arrays[i] = new long long[S];   //DMA for a 2D array
    }

    int indexes[10] = {0};          //an array of indexes for each of the 10 arrays
    for (int i = 0; i < S; i++)
    {
        char digit = people[i].firstDigit();
        switch (digit)
        {
        case '0':
            arrays[0][indexes[0]++] = stoi(people[i].getcnic());
            break;
        case '1':
            arrays[1][indexes[1]++] = stoi(people[i].getcnic());
            break;
        case '2':
            arrays[2][indexes[2]++] = stoi(people[i].getcnic());
            break;
        case '3':
            arrays[3][indexes[3]++] = stoi(people[i].getcnic());
            break;
        case '4':
            arrays[4][indexes[4]++] = stoi(people[i].getcnic());
            break;
        case '5':
            arrays[5][indexes[5]++] = stoi(people[i].getcnic());
            break;
        case '6':
            arrays[6][indexes[6]++] = stoi(people[i].getcnic());
            break;
        case '7':
            arrays[7][indexes[7]++] = stoi(people[i].getcnic());
            break;
        case '8':
            arrays[8][indexes[8]++] = stoi(people[i].getcnic());
            break;
        case '9':
            arrays[9][indexes[9]++] = stoi(people[i].getcnic());
            break;
        }
    }
    return arrays;
}
int main()
{
    srand(time(0));
    long long range = 10000000000000;
    const long long S = 100000;
    Person people[S];
    for (int i = 0; i < S; i++)
    {
        people[i].setcnic(rand() % range); //setting random CNIC
    }
    string findCNIC = to_string(rand() % range);        //an unknown cnic to search
    char findDigit = findCNIC[0];

    

    long long **arrays = dictionary(people, S);     //setting up the dictionary structure
    bool check;
    uint64_t ms = gettime();
    
    switch (findDigit)
    {
    case '0':
        check = searching(arrays[0], stoi(findCNIC), S);    //check if cnic is present or not  
        break;              
    case '1':
        check = searching(arrays[1], stoi(findCNIC), S);
        break;
    case '2':
        check = searching(arrays[2], stoi(findCNIC), S);
        break;
    case '3':
        check = searching(arrays[3], stoi(findCNIC), S);
        break;
    case '4':
        check = searching(arrays[4], stoi(findCNIC), S);
        break;
    case '5':
        check = searching(arrays[5], stoi(findCNIC), S);
        break;
    case '6':
        check = searching(arrays[6], stoi(findCNIC), S);
        break;
    case '7':
        check = searching(arrays[7], stoi(findCNIC), S);
        break;
    case '8':
        check = searching(arrays[8], stoi(findCNIC), S);
        break;
    case '9':
        check = searching(arrays[9], stoi(findCNIC), S);
        break;
    }
    if(check)
    {
        cout<<"FOUND!\n";
    }
    else
    {
        cout<<"NOT FOUND!"<<endl;
    }
    uint64_t ms2 = gettime();

    cout << "Diff in time: " << ms2 - ms << endl;
    return 0;
}