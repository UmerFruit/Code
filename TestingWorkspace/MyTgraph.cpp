#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
template <class T>
class Graphnode
{
public:
	vector<Graphnode<T> *> links;
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
	Graphnode<T> *findvert(T data)
	{
		for (int i = 0; i < vertices.size(); i++)
		{
			if (vertices[i].data == data)
			{
				return &vertices[i];
			}
		}
		return NULL;
	}
	void
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
			cout << srcdata << " already has " << destdata << endl;
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
	void bfs(T start)
	{
		bool *visited = new bool[vertices.size()];
		for (int i = 0; i < vertices.size(); i++)
			visited[i] = false;
		vector<T> ans;
		for (int i = 0; i < vertices.size(); i++)
		{
			if (!visited[i])
			{ /*
			   * Front maango
			   * queue mai push karo
			   * visited mark
			   * print
			   * queue mai adjlist push karo
			   * repeat
			   */
				queue<Graphnode<T> *> q;
				q.push(findvert(start));
				visited[start] = true;
				while (!q.empty())
				{
					Graphnode<T> *f = q.front();
					q.pop();
					ans.push_back(f->data);
					for (int i = 0; i < f->links.size(); i++)
					{
						if (!visited[f->links[i]->data])
						{
							q.push(f->links[i]);
							visited[f->links[i]->data] = true;
						}
					}
				}
			}
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	void DFS(bool visited[5], vector<T> &ans, int node)
	{
		if (!visited[node])
		{
			ans.push_back(node);
			visited[node] = true;
			Graphnode<T> *list = findvert(node);
			for (int i = 0; i < list->links.size(); i++)
			{
				DFS(visited, ans, list->links[i]->data);
			}
		}
	}
	void dfs(T start)
	{
		bool visited[5] = {0};
		vector<T> ans;
		for (int node = 0; node < vertices.size(); node++)
		{
			if (!visited[node])
			{
				DFS(visited, ans, node);
			}
		}
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
};

int main()
{
	Graph<int> g(0); // 0 for undirected graph
	for (int i = 0; i < 6; i++)
	{
		g.addvert(i);
	}
	int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5;
	g.addedge(a, b);
	g.addedge(a, d);
	g.addedge(a, e);
	g.addedge(b, c);
	g.addedge(c, e);
	g.addedge(c, f);
	g.addedge(d, e);
	g.addedge(e, f);
	// g.print();
	g.bfs(0);
}
