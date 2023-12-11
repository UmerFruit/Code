#include <iostream>
#include <iomanip>
#include <list>
#include "Dictionary.h"
using namespace std;
int main()
{
   Dictionary<int , list<int>> d;
   d.add(1, {1, 2, 3});
   d.add(2, {4, 5, 6});
   d.add(3, {7, 8, 9});
   d.add(4, {10, 11, 12});
   d.remove(3);
   for (int i = 1; i <= 4; i++)
   {
      cout << i << " -> ";
      for (int& j : d[i])
      {
         cout << j << " ";
      }
      cout << endl;
   }
   
   
}
