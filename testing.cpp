#include <iostream>
#include <iomanip>
#include <list>
#include "Dictionary.h"
using namespace std;
int main()
{
   Dictionary<int, string> d;
   d.add(1, "one");
   d.add(2, "two");
   d.add(3, "three");
  
   d[42];
}
