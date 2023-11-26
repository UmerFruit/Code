#ifndef GRAPH_H_
#define GRAPH_H_
#include "Headers.h"
using namespace std;
template <class T>
class Graph
{
public:
    List<T> *adjList;
    int vert;
    Graph(int nodes)
    {
        adjList = new List<T>[nodes];
        vert = nodes;
        for (int i = 0; i < vert; i++)
        {
            adjList[i].Push(i);
        }
    }
    void insertEdge(int src, int dest)
    {
        adjList[src].Push(dest);
        // arr[dest].insert(source);
    }
    void showGraphStrct()
    {
        for (int i = 0; i < vert; i++)
            adjList[i].display();
    }
    ~Graph()
    {
        delete[] adjList;
    }
};
#endif /* HEAP_H_ */