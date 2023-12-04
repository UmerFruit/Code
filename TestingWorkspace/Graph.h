#ifndef GRAPH_H_
#define GRAPH_H_
#include "Location.h"
using namespace std;
class ANode
{
public:
    pairs ;
        ANode *next;
    ANode(string s)
    {
        this->data = s;
        this->next = NULL;
    }
};
class AdjList
{
public:
    ANode *head;
    AdjList()
    {
        head = NULL;
    }
    void insert(string data)
    {
        if (head == NULL)
        {
            head = new ANode(data);
        }
        else
        {
            ANode *temp = new ANode(data);
            ANode *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = temp;
        }
    }
    void Display()
    {
        for (ANode *curr = head; curr != NULL; curr = curr->next)
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
    vector<> list;
    int vert;
    Graph(vector<Student> s)
    {
        vert = s.size();

        for (int i = 0; i < vert; i++)
        {
            list.push_back(AdjList());
            list[i].insert(s[i].name);
        }
    }
    void addvert(Student &l)
    {
        list.push_back(AdjList());
        list[list.size() - 1].insert(l.name);
        vert++;
    }
    void insertEdge(string src, string dest)
    {
        int sidx;
        int didx;

        for (int i = 0; i < vert; i++)
        {
            if (list[i].head->data == src)
                sidx = i;

            if (list[i].head->data == dest)
                didx = i;
        }
        list[sidx].insert(dest);
        list[didx].insert(src);
    }
    void showGraphStrct()
    {
        cout << "Graph: " << endl;
        for (int i = 0; i < vert; i++)
            list[i].Display();
    }

    ~Graph()
    {
    }
};
#endif // GRAPH_H_INCLUDED
