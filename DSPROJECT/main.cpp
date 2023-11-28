#include "Headers.h"
using namespace std;
int main()
{
    Graph<string,int> g(5);
    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 2);
    g.insertEdge(1, 3);
    g.insertEdge(2, 3);
    g.insertEdge(2, 4);
    g.insertEdge(3, 4);
    g.insertEdge(4, 3);
    g.insertEdge(3, 2);
    g.showGraphStr();
    g.showGraph();
    return 0;
    //umer humayun maleek saif bilal
}
