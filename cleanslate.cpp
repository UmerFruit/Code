#include "Headers.h"
using namespace std;
int main()
{
    char** grid = new char* [30];
    for (int i = 0; i < 30; i++)
    {
        *(grid + i) = new char[30];
    }
    
}
