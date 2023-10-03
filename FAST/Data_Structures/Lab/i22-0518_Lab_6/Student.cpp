 #include <iostream>
#include <cstring>
using namespace std;
class Student
{
private:
    string ID;
    string name;
    float CGPA;
    int age;

public:
    Student()
    {
        ID = "0";
        name = "Umer Farooq";
        CGPA = 0;
        age = 88;
    }
    Student(string ID, string name, float cgpa, int a)
    {
        this->ID = ID;
        this->name = name;
        CGPA = cgpa;
        age = a;
    }
    void setCGPA(float cgpa)
    {
        CGPA = cgpa;
    }
    float getCGPA()
    {
        return CGPA;
    }
    string getid()
    {
        return ID;
    }
    friend ostream &operator<<(ostream &out, Student &lol);
};
ostream &operator<<(ostream &out, Student &lol)
{
    cout << "ID = " << lol.ID << endl;
    cout << "Name = " << lol.name << endl;
    cout << "CGPA = " << lol.CGPA << endl;
    cout << "Age = " << lol.age << endl;
    return out;
}
