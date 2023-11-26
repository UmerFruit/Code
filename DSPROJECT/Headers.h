
#ifndef HEADERS_H_
#define HEADERS_H_
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include <vector>
#include "Heap.h"
#include "Graph.h"
template <class T1,class T2>
class Pair
{
public:
    T1 first;
    T2 second;
    Pair(T1 f, T2 s)
    {
        first = f;
        second = s;
    }
};

using namespace std;
#endif /* HEADERS_H_ */
