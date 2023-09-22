/*
23 May 2023
This is my implementation of the hashmap function SHA-3 as it was presented in our OOP final exam.
The question presented was as follows:

"You are required to implement a generic Hashmap algorithm using a template class which takes a 1600 element input, transforms it into a slate of 5x5x64 grid and outputs a 100 element output.The grid will have an x,y,z triple where 0 ≤ x < 5 , 0 ≤ y < 5 , 0 ≤ z < 64.The naming convention is as follows in the diagram included in the folder. This class will have the following functions:
Constructors:
    2 constructors, parameterized and non parameterized.
    The parameterized constructor takes a 1600 element input and sets it up as the input of the SHA.
    The non-parameterized constructor generates a 1600 element input by itself and sets it up as the input of SHA.
Private Functions:
    Rotateslice: 
        It will swap the slices by 1 i.e slice 1 becomes 2, slice 4 becomes 3 and so on.
    Rotateplane: 
        It will swap the planes by 4 i.e plance 1 becomes 4, plane 2 becomes 5 , plane 3 becomes 1 (they swap around as there are only 5 planes), plane 4 and 5 become 2 and 3 respectively.
    Rotatesheet: 
        It works the same way as Rotateplane but just works on sheets instead of planes.
    NOTE: They return the this pointer to make use of cascading calls.
Public Functions:
    Transform: 
        Divides the 1600 element input into 25 element chunks to store in the 3D array. e.g if input chunk is "abcdefghijklmnopqrstuvwxy" it should be stored as:
        a b c d e
        f g h i j
        k l m n o
        p q r s t
        u v w x y
        in the 5x5 slice.
    CalculateHash Function:
        This function takes the 3D array and applies the rotateslice, rotateplance and rotatesheet processes in order NR number of times (NR is data member set through a setter) using cascading calls and outputs the first 100 elements of the 1600 element output of the hash.
    == Operator Overload:
        Checks if the first 100 elements of two hashes are equal.
    Destructor:
        Appropriately deallocates the dynamic memory
*/
#include <iostream>
using namespace std;
int main()
{
   
}
