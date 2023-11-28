#ifndef GRAPH_H_
#define GRAPH_H_
using namespace std;

class Graph
{
public:
    List< *list;
    int vert;
    Graph(int nodes)
    {
        list = new AdjList[nodes];
        vert = nodes;
        for (int i = 0; i < vert; i++)
        {
            list[i].insert(i);
        }
    }
    void insertEdge(int src, int dest)
    {
        list[src].insert(dest);
        // arr[dest].insert(source);
    }
    void showGraphStrct()
    {
        cout << "Graph: " << endl;
        for (int i = 0; i < vert; i++)
            list[i].Display();
    }
    bool checkcycleUtil(AdjList *arr, bool *visited, bool *dfsVisited, int node)
    {
        visited[node] = true;
        dfsVisited[node] = true;

        for (Node *temp = arr[node].head->next; temp; temp = temp->next)
        {
            int x = temp->data;
            if (visited[x] == 0)
            {
                bool ans = checkcycleUtil(arr, visited, dfsVisited, x);

                if (ans)
                {
                    return ans;
                }
            }
            else if (dfsVisited[x] == 1)
            {
                return true;
            }
        }
        dfsVisited[node] = false;
        return false;
    }

    bool checkcycle()
    {
        bool *visited = new bool[vert];
        bool *dfsvisited = new bool[vert];
        for (int i = 0; i < vert; i++)
        {
            visited[i] = false;
            dfsvisited[i] = false;
        }
        for (int i = 0; i < vert; i++)
        {
            if (visited[i] == 0)
            {
                bool ans = checkcycleUtil(list, visited, dfsvisited, i);

                if (ans)
                {
                    return ans;
                }
            }
        }

        return false;
    }

    ~Graph()
    {
        delete[] list;
    }
};
#endif // GRAPH_H_INCLUDED
