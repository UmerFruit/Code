#include <iostream>
#include <string>
using namespace std;
// void powset(int* arr,int* pset,int i);
// void exclude(int a,int* pset);
// void include(int a,int* pset);
// int main()
// {
//     int arr[10] = {2, 4, 1, 5, 3, 6, 8, 9, 10, 7};
//     int as[10];
//     for (int i = 0; i < 10; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     cpy(arr,as,10);
//     for (int i = 0; i < 10; i++)
//     {
//         cout << as[i] << " ";
//     }
// }

// void powset(int* arr,int* pset,int i)
// {
//     if(i==0)
//     {
//         return;
//     }
//     exclude(arr[i-1],pset);
//     include(arr[i-1],pset);
// }
// void exclude(int a,int* pset);
// int* include(int a)
// {
    
// }

string reverseStringRecursive(string str) {
    // Base case: if the string is empty or contains only one word
    if (str.empty() || str.find(' ') == string::npos) {
        return str;
    } else {
        // Find the index of the first space
        size_t spaceIndex = str.find(' ');

        // Extract the first word and recursively reverse the remaining string
        string remainingString = str.substr(spaceIndex + 1);
        string reversedRemaining = reverseStringRecursive(remainingString);

        // Combine the reversed remaining string with the first word and return the result
        string firstWord = str.substr(0, spaceIndex);
        string reversedString = reversedRemaining + " " + firstWord;

        return reversedString;
    }
}

int main() {
    string inputString = "my name is umer";
    string outputString = reverseStringRecursive(inputString);
    cout << outputString << endl;

    return 0;
}