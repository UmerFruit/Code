#include <iostream>
using namespace std;

class Engine {
public:
    int cylinders;

    Engine(int numCylinders) : cylinders(numCylinders) {
        cout << "Creating Engine with " << cylinders << " cylinders" << endl;
    }
    ~Engine() { cout << "Destroying Engine with " << cylinders << " cylinders" << endl; }

};

class Car {
public:
    Engine engine;
    string make;
    string model;

    Car(const string& carMake, const string& carModel, int numCylinders)
        : engine(numCylinders), make(carMake), model(carModel) {
        cout << "Creating " << make << " " << model << " with " << numCylinders << " cylinders" << endl;
    }
    ~Car() { cout << "Destroying " << make << " " << model << " with " << engine.cylinders << " cylinders" << endl; }
};

class Person {
public:
    string name;

    Person(const string& personName) : name(personName) { 
        cout << "Creating Person named " << name << endl; 
    }
    ~Person() { cout << "Destroying Person named " << name << endl; }
};

class Driver {
private:
    Person person;
    Car car;
public:
    Driver(const string& driverName, const string& carMake, const string& carModel, int numCylinders)
        : person(driverName), car(carMake, carModel, numCylinders) {
        cout << "Creating Driver named " << driverName << " with " << carMake << " " << carModel << " with " << numCylinders << " cylinders" << endl;
    }
    ~Driver() { cout << "Destroying Driver named " << person.name << " with " << car.make << " " << car.model << " with " << car.engine.cylinders << " cylinders" << endl; }
};



int main() {

    Car myCar("Honda", "Civic", 4);

    Person myPerson("Alice");
    Driver myDriver("Bob", "Toyota", "Corolla", 4);

    {
        Driver myDriver("Charlie", "Ford", "Mustang", 8);
       
    }


    return 0;
}
/*
Creating Engine with 4 cylinders
Creating Honda Civic with 4 cylinders
Creating Person named Alice
Creating Person named Bob
Creating Engine with 4 cylinders
Creating Toyota Corolla with 4 cylinders
Creating Driver named Bob with Toyota Corolla with 4 cylinders

Creating Person named Charlie
Creating Engine with 8 cylinders
Creating Ford Mustang with 8 cylinders
Creating Driver named Charlie with Ford Mustang with 8 cylinders

Destroying Driver named Charlie with Ford Mustang with 8 cylinders
Destroying Ford Mustang with 8 cylinders
Destroying Engine with 8 cylinders
Destroying Person named Charlie

Destroying Driver named Bob with Toyota Corolla with 4 cylinders
Destroying Toyota Corolla with 4 cylinders
Destroying Engine with 4 cylinders
Destroying Person named Bob

Destroying Person named Alice

Destroying Honda Civic with 4 cylinders
Destroying Engine with 4 cylinders

*/