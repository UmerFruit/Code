#ifndef LOCATION_H_
#define LOCATION_H_
#include "Headers.h"
using namespace std;
class location
{
public:
    string name;
    string sector;
    bool isbin;
    location()
    {
        name = "";
        sector = "";
        isbin = 0;
    }
    location(string n, string s, bool b)
    {
        name = n;
        sector = s;
        isbin = b;
    }
    location(const location &l1)
    {
        name = l1.name;
        sector = l1.sector;
        isbin = l1.isbin;
    }
    void setname(string n)
    {
        name = n;
    }
    void setsector(string s)
    {
        sector = s;
    }
    void setisbin(bool x)
    {
        isbin = x;
    }
    void print()
    {
        cout << "Street Name: " << name << endl;
        cout << "Secotor: " << sector << endl;
        if (!isbin)
        {
            cout << "Its a Bin" << endl;
        }
        else
        {
            cout << "Its a Dumping/Departure point" << endl;
        }
    }
};
ostream &operator<<(ostream &out, location &l)
{
    l.print();
    return out;
}
class pairs
{
public:
    location place;
    int distance;
    pairs()
    {
        distance = -1;
    }
    pairs(location s1, int n)
    {
        place = s1;
        distance = n;
    }
    pairs(const pairs &p1)
    {
        place = p1.place;
        distance = p1.distance;
    }
    void print()
    {
        cout << "First : " << place << endl;
        cout << "Second : " << distance << endl;
    }
};
ostream &operator<<(ostream &out, pairs &p)
{
    p.print();
    return out;
}
class node
{
public:
    pairs data;
    node *next;
    node(pairs &x)
    {
        data = x;
        next = NULL;
    }
};
class adjlist
{
public:
    node *head;
    node *tail;
    adjlist()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(pairs &x)
    {
        if (head == NULL)
        {
            head = new node(x);
            tail = head;
            return;
        }
        else
        {
            tail->next = new node(x);
            tail = tail->next;
        }
        return;
    }
    void print()
    {
        if (head == NULL)
        {
            cout << "List empty" << endl;
            return;
        }
        cout << "Vertice : " << head->data << " , Neighbours: ";
        for (node *i = head->next; i != NULL; i = i->next)
        {
            cout << i->data << " ";
        }
        cout << endl;
    }
};
class Graph
{
public:
    vector<adjlist> arr;
    int vert;

    Graph()
    {
    }
    void insert(vector<location> &v1)
    {
        vert = v1.size();
        pairs p1;
        for (int i = 0; i < vert; i++)
        {
            arr.push_back(adjlist());
            p1.place = v1[i];
            arr[i].insert(p1);
        }
    }
    void showGraphStructure()
    {
        for (int i = 0; i < vert; i++)
        {
            arr[i].print();
            cout << endl;
        }
    }
};
#endif