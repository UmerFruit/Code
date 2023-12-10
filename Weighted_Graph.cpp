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
    void addVert(T data)
    {
        vertices.push_back(Graphnode<T>(data));
    }
    void addEdge(T srcdata, T destdata, int w)
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
    void djalgo()
    {
        
    }
};
int main()
{
	// Create a graph given in the above diagram
	Graph<int> g(0);
	for (int i = 0; i < 4; i++)
		g.addVert(i);
	g.addEdge(0, 1, 5);
	g.addEdge(0, 2, 8);
	g.addEdge(1, 2, 9);
	g.addEdge(1, 3, 2);
	g.addEdge(2, 3, 6);

	g.print();
	return 0;
}
