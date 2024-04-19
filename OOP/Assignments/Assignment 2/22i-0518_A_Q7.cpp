/*
 *  Name : Umer Farooq
 *  Student ID : 22I-0518
 *  Assignment# 2
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
    char *rollnum;
    char *name;
    int batch;
    int Courses_Code[5];
    char *Courses_Name[5]; // data members
    char Courses_Grades[5];
    float CGPA;
    char *Degree;
    char *DOB;

public:
    Student();
    Student(char *r, char *n, int b, int code[], char *name[], char grade[], float cgpa, char *deg, char *dob);
    friend void print(Student s);
    void setValues();
    void setBatch(int batch);
    void setCgpa(float cgpa);
    void setCoursesCode(int coursesCode, int);
    void setCoursesGrades(char coursesGrades, int); // member functions
    void setCoursesName(char *coursesName, int);
    void setDegree(char *degree);
    void setDob(char *dob);
    void setName(char *name);
    void setRollnum(char *rollnum);
};
Student::Student()
{
    rollnum = new char[25];
    name = new char[25];
    DOB = new char[15]; // DMA
    Degree = new char[10];

    rollnum = "i22-0518";
    name = "Umer Farooq";
    batch = 22;
    CGPA = 3.7;
    DOB = "11-05-2004";
    Degree = "BS(CY)"; // Some initial values
    for (int i = 0; i < 5; i++)
    {
        Courses_Name[i] = new char[40];
        Courses_Code[i] = 0;
        Courses_Grades[i] = 'F';
        Courses_Name[i] = "OOP";
    }
}
Student::Student(char *r, char *n, int b, int code[], char *name[], char grade[], float cgpa, char *deg, char *dob)
{
    rollnum = new char[25];
    this->name = new char[25];
    DOB = new char[15];
    Degree = new char[25];

    rollnum = r;
    this->name = n;
    batch = b;
    CGPA = cgpa; // Parameterized constructor
    DOB = dob;
    Degree = deg;
    for (int i = 0; i < 5; i++)
    {
        Courses_Name[i] = new char[40];
        Courses_Code[i] = code[i];
        Courses_Grades[i] = grade[i];
        Courses_Name[i] = name[i];
    }
}
void Student::setValues()
{
    rollnum = new char[25];
    this->name = new char[25];
    DOB = new char[15];
    Degree = new char[25];
    for (int i = 0; i < 5; i++)
    {
        if (i)
            cin.ignore();
        Courses_Name[i] = new char[40];
        cout << "Enter Course Name" << endl;
        cin.getline(Courses_Name[i], 40); // Setter for all values via user input
        cout << "Enter course code" << endl;
        cin >> Courses_Code[i];
        cout << "Enter course Grade" << endl;
        cin.ignore();
        cin >> Courses_Grades[i];
    }
    cout << "Enter batch" << endl;
    cin >> batch;
    cout << "Enter roll-number" << endl;
    cin.ignore();
    cin.getline(rollnum, 25);
    cout << "Enter name" << endl;
    cin.getline(name, 25);
    cout << "Enter CGPA" << endl;
    cin >> CGPA;
    cout << "Enter DOB" << endl;
    cin.ignore();
    cin.getline(DOB, 15);
    cout << "Enter Degree" << endl;
    cin.getline(Degree, 25);
}
void Student::setBatch(int batch)
{
    this->batch = batch; // setters
}

void Student::setCgpa(float cgpa)
{
    CGPA = cgpa;
}

void Student::setCoursesCode(int coursesCode, int index)
{
    Courses_Code[index] = coursesCode;
}

void Student::setCoursesGrades(char coursesGrades, int index)
{
    Courses_Grades[index] = coursesGrades;
}

void Student::setCoursesName(char *coursesName, int index)
{
    Courses_Name[index] = coursesName;
}

void Student::setDegree(char *degree)
{
    Degree = degree;
}

void Student::setDob(char *dob)
{
    DOB = dob;
}

void Student::setName(char *name)
{
    this->name = name;
}

void Student::setRollnum(char *rollnum)
{
    this->rollnum = rollnum;
}
void print(Student s) // print utility function in transcript form
{
    cout << setw(100) << setfill('-') << "" << endl
         << setfill(' ');
    cout << "| "
         << "Student Name:\t " << setw(56) << left << s.name;
    cout << "Roll No:\t " << setw(10) << left << s.rollnum << "|" << endl;
    cout << "| "
         << "Date of Birth: " << setw(20) << left << s.DOB;
    cout << "Univ. Reg. No:  " << setw(20) << left << s.rollnum;
    cout << "Degree:\t " << setw(10) << left << s.Degree << "|" << endl;
    cout << "|" << setw(99) << right << "|" << endl;
    cout << "|" << setw(50) << right << "Fall - " << setw(48) << left << s.batch << "|" << endl;
    cout << "|";
    cout << setw(12) << " "
         << setw(73) << setfill('-') << " " << setfill(' ')
         << setw(15) << right << "| " << endl
         << "|";
    cout << setw(13) << "";

    cout << "| " << setw(20) << left << "Code" << setw(30) << left << "Course Title" << setw(5) << left << "Crd" << setw(5) << left << "PNT" << setw(5) << left << "GRD" << setw(4) << left << "RNK"
         << "|" << setw(14) << right << "|" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "|";
        cout << setw(13) << "";
        cout << "| " << setw(10) << left << s.Courses_Code[i];
        cout << setw(40) << left << s.Courses_Name[i];
        cout << setw(5) << left << "3";
        switch (s.Courses_Grades[i])
        {

        case 'a':
        case 'A':
            cout << setw(5) << left << "4";
            break;
        case 'b':
        case 'B':
            cout << setw(5) << left << "3";
            break;
        case 'c':
        case 'C':
            cout << setw(5) << left << "2";
            break;
        case 'd':
        case 'D':
            cout << setw(5) << left << "1";
            break;
        case 'f':
        case 'F':
            cout << setw(5) << left << "0";
            break;
        }
        cout << setw(5) << left << s.Courses_Grades[i];
        cout << setw(4) << left << "NC"
             << "|";
        cout << setw(14) << right << "|" << endl;
    }
    cout << setw(13) << left << "|"
         << setw(73) << setfill('-') << " " << setfill(' ')
         << setw(15) << right << "| " << endl;
    cout << setw(18) << left << "|";
    cout << "Credits Attempted:\t15"
         << setw(35) << right << "GPA:\t" << setw(19) << left << s.CGPA << "|" << endl;
    cout << setw(18) << left << "|";
    cout << "Credits Earned:\t15"
         << setw(35) << right << "CGPA:\t" << setw(19) << left << s.CGPA << "|" << endl;
    cout << setw(100) << setfill('-') << "" << endl
         << setfill(' ');
}
void studentDemo() // funtion to demonstrate all member functions
{
    Student lol;

    char g[7] = "AAAAA";
    cout << "\nBefore Change\n\n";
    print(lol);
    lol.setBatch(30);
    lol.setCgpa(0);
    lol.setCoursesCode(12345, 0);
    lol.setCoursesGrades('A', 0);
    lol.setCoursesName("PST", 0);
    lol.setDegree("BS-SE");
    lol.setDob("15-2-1900");
    lol.setName("Abdullah");
    lol.setRollnum("i19-0122");
    cout << "\nAFTER change\n\n";
    print(lol);
    lol.setValues();
    cout << "\n\nAfter SETVALUES\n";
    print(lol);
}

int main()
{
    //   studentDemo();
}