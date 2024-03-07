#include <iostream>
#include <stdio.h>
using namespace std;
// Defining an enumeration type called Color
enum Color {
    Red,
    Green,
    Blue
};

int main() {
    // Declaring a variable of type Color and initializing it with a value from the enumeration
    Color c = Red;

    // Switch statement to perform different actions based on the value of color
    switch (c) {
        case Color::Red:
            cout << "The color is Red." << endl;
            cout<<Bluew<<endl;;
            break;
        case Color::Green:
            cout << "The color is Green." << endl;
            break;
        case Color::Blue:
            cout << "The color is Blue." << endl;
            break;
    }

    return 0;
}
