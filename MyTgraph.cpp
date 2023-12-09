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
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	void dfs(T start)
	{
		bool visited[5] = {0};
		vector<T> ans;
		for (int i = 0; i < vertices.size(); i++)
			if (!visited[i])
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
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	bool cycleutil()
	{
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
	void cycleBFS()
	{
		bool visited[9] = {0};
		for (int i = 0; i < vertices.size(); i++)
		{
			if (!visited[i])
			{
				bool ans = cycleutil(i,visited,);
				if(ans == 1)
					return true;
			}
		}
		return false;
	}
};

// bool checkcycleUtil(AdjList *arr, bool *visited, bool *dfsVisited, int node)
// {
// 	visited[node] = true;
// 	dfsVisited[node] = true;
// 	for (Node *temp = arr[node].head->next; temp; temp = temp->next)
// 	{
// 		int x = temp->data;
// 		if (visited[x] == 0)
// 		{
// 			bool ans = checkcycleUtil(arr, visited, dfsVisited, x);
// 			if (ans)
// 			{
// 				return ans;
// 			}
// 		}
// 		else if (dfsVisited[x] == 1)
// 		{
// 			return true;
// 		}
// 	}
// 	dfsVisited[node] = false;
// 	return false;
// }
// bool checkcycle()
// {
// 	bool *visited = new bool[vert];
// 	bool *dfsvisited = new bool[vert];
// 	for (int i = 0; i < vert; i++)
// 	{
// 		visited[i] = false;
// 		dfsvisited[i] = false;
// 	}
// 	for (int i = 0; i < vert; i++)
// 	{
// 		if (visited[i] == 0)
// 		{
// 			bool ans = checkcycleUtil(list, visited, dfsvisited, i);
// 			if (ans)
// 			{
// 				return ans;
// 			}
// 		}
// 	}
// 	return false;
// }

int main()
{
	Graph<int> g(0); // 0 for undirected graph
	for (int i = 0; i < 6; i++)
	{
		g.addvert(i);
	}
	g.addedge(0, 1);
	g.addedge(0, 3);
	g.addedge(0, 4);
	g.addedge(1, 2);
	g.addedge(2, 4);
	g.addedge(2, 5);
	g.addedge(3, 4);
	g.addedge(4, 5);
	g.dfs(0);
	// g.print();
	// g.bfs(0);
}
