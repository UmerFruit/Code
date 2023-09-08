//---------------------Question # 14---------------------//
#include <iostream>
using namespace std;
class StudentInfo
{
public:
    StudentInfo()
    {
        cout << "StudentInfo() called" << endl;
    }

    ~StudentInfo()
    {
        cout << "Dest-StudentInfo() called" << endl;
    }
};
class Students
{
public:
    Students()
    {
        cout << "Students() called" << endl;
    }

    StudentInfo info;

    ~Students()
    {
        cout << "Dest-Students() called" << endl;
    }
};

class AcademicInstitutions
{
public:
    AcademicInstitutions()
    {
        cout << "AcademicInstitutions() called" << endl;
    }

    ~AcademicInstitutions()
    {
        cout << "Dest-AcademicInstitutions() called" << endl;
    }
};

class Universities : public AcademicInstitutions
{
    Students Aneeq;

public:
    Universities()
    {
        cout << "Universities() called" << endl;
    }

    ~Universities()
    {
        cout << "Dest-Universities() called" << endl;
    }
};

class PrivateUniversity : public Universities
{
public:
    PrivateUniversity()
    {
        cout << "PrivateUniversity() called" << endl;
    }
    ~PrivateUniversity()
    {
        cout << "Dest-PrivateUniversity() called" << endl;
    }
};

int main()
{

    AcademicInstitutions *inst = new PrivateUniversity;
    delete inst;
}
/*
AcademicInstitutions() called
StudentInfo() called
Students() called
Universities() called
PrivateUniversity() called

Dest-PrivateUniversity() called
Dest-Universities() called
Dest-Students() called
Dest-StudentInfo() called
Dest-AcademicInstitutions() called




*/