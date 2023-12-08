#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
class Graphnode
{
public:
    vector<pair<Graphnode<T> *, int>> links;
    T data;
    Graphnode(T d)
    {
        data = d;
        links.clear();
    }
};
template <class T>
class Graph
{
    vector<Graphnode<T>> vertices;
    bool directed;

public:
    Graph(bool i = 0)
    {
        directed = i;
    }
    void addvert(T data)
    {
        vertices.push_back(Graphnode<T>(data));
    }
    void addedge(T srcdata, T destdata, int w)
    {
        Graphnode<T> *src = NULL, *dest = NULL;
        for (int i = 0; i < vertices.size(); i++)
        {
            if (vertices[i].data == srcdata)
            {
                src = &vertices[i];
            }
            if (vertices[i].data == destdata)
            {
                dest = &vertices[i];
            }
        }
        if (src == NULL || dest == NULL)
        {
            cout << "Invalid Vertices" << endl;
            return;
        }
        if (find(src->links.begin(), src->links.end(), make_pair(dest, w)) == src->links.end())
        {
            src->links.push_back(make_pair(dest, w));
            if (directed == false)
            {
                dest->links.push_back(make_pair(src, w));
            }
        }
        else
            cout << "Dest edge already exists in Src" << endl;
        return;
    }
    void print()
    {
        for (int i = 0; i < vertices.size(); i++)
        {

            cout << vertices[i].data << " : ";
            for (int j = 0; j < vertices[i].links.size(); j++)
            {
                cout << " (" << vertices[i].links[j].first->data << "," << vertices[i].links[j].second << ") ,";
            }
            cout<<"\b "; // remove last comma
            cout << endl;
        }
    }
};