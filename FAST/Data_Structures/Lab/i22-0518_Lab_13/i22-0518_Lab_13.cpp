#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class AdjList
{
public:
    Node *head;
    AdjList()
    {
        head = NULL;
    }
    void insert(int data)
    {
        if (head == NULL)
        {
            head = new Node(data);
        }
        else
        {
            Node *temp = new Node(data);
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void Display()
    {
        for (Node *curr = head; curr != NULL; curr = curr->next)
        {
            cout << curr->data;
            curr == head ? cout << ": " : cout << " ";
        }
        cout << endl;
    }
};
class Graph
{
public:
    AdjList *list;
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
int main()
{
    /*
        0 : 3
        1 : 2,3,4
        2 : 1
        3 : 0,1
        4 : 1
    */
    Graph g(5);
    g.insertEdge(0, 1);
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(3, 4);
    g.insertEdge(4, 2);   //comment to show Acyclic 

    cout << "Graph is ";
    if (!g.checkcycle())
    {
        cout << " not ";
    }
    cout << "cyclic\n";
    g.showGraphStrct();
}