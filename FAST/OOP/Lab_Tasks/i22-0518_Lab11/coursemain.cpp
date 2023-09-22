#include "Course.h"
int main()
{
    Textbook t1 ("math","david",5);
    Textbook t2 ("science","ahmed",1);
    Textbook t3 ("C++","tony gaddis",2);
    Instructor i1("Umer","Farooq","142-A","Professor");
    Instructor i2("Ahmed","Shehzad","196-B","Lab instructor");
    Instructor i3("Humayun","Masaud","100-C","cleaner");
    Course** c = new Course* [3];
    c[0] = new Course(i1,t1);
    c[1] = new Course(i2,t2);
    c[2] = new Course(i3,t3);
    c[0][0].print();

}