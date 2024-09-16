#include <iostream>
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
        // arr[dest].insert(source); //uncomment for undirected graph
    }
    void showGraphStrct()
    {
        cout << "Graph: " << endl;
        for (int i = 0; i < vert; i++)
            list[i].Display();
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
    g.insertEdge(0, 3);
    g.insertEdge(1, 2);
    g.insertEdge(2, 3);
    g.insertEdge(3, 4);
    g.insertEdge(4, 2);   //comment to show Acyclic 
    cout << "Graph is ";
    g.showGraphStrct();
}