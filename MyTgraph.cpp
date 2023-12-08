#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
class Graphnode
{
public:
	vector<Graphnode *> links;
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
	void addedge(T srcdata, T destdata)
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
		if (find(src->links.begin(), src->links.end(), dest) == src->links.end())
		{
			src->links.push_back(dest);
			if (directed == false)
			{
				dest->links.push_back(src); // comment for directed graph
			}
		}
		else
			cout << "dest Edge already exists in src" << endl;
		return;
	}
	void print()
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			Graphnode<T> *curr = &vertices[i];
			cout << curr->data << " : ";
			for (int j = 0; j < curr->links.size(); j++)
			{
				cout << curr->links[j]->data << " ";
			}
			cout << endl;
		}
	}
};
int main()
{
	Graph<int> g(0); // 0 for undirected graph
	g.addvert(1);
	g.addvert(2);
	g.addvert(3);
	g.addvert(4);
	g.addvert(5);
	g.addedge(1, 2);
	g.addedge(2, 1);

	// g.addedge(2, 1);
	// g.addedge(2, 1);
	// g.addedge(1, 3);
	// g.addedge(2, 4);
	// g.addedge(3, 4);
	// g.addedge(4, 5);
	// g.addedge(5, 1);
	g.print();
	// Graph<string> g2(1);	// 1 for directed graph
	// g.addvert("Saif");
	// g.addvert("Humayun");
	// g.addvert("Bilal");
	// g.addvert("Umer");
	// g.addvert("Munim");
	// g.addvert("Tiddy");
	// g.addvert("Emaan");
	// g.addvert("Mohaiman");
	// g.addedge("Umer", "Saif");
	// g.addedge("Humayun", "Bilal");
	// g.addedge("Bilal", "Munim");
	// g.addedge("Munim", "Tiddy");
	// g.addedge("Tiddy", "Munim");
	// g.addedge("Tiddy", "Emaan");
	// g.addedge("Emaan", "Mohaiman");
	// g.addedge("Mohaiman", "Umer");
	// g.print();
}
