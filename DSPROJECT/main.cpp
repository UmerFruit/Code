#include "Headers.h"
using namespace std;
int main()
{
    Graph<int> g(5);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    g.insertEdge(2, 4);
    g.insertEdge(3, 4);
    g.insertEdge(4, 5);
    g.insertEdge(3, 5);
    g.showGraphStrct();
    return 0;
}
