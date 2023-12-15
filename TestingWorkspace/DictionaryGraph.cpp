#include "Headers.h"
#include "Dictionary.h"
using namespace std;

template <class T>
class Graph
{
public:
   Dictionary<T, vector<T> > adj;
   bool directed;

   Graph(bool directed = false)
   {
      this->directed = directed;
   }
   void addvert(T u)
   {
      adj.add(u, vector<T>());
   }
   void addEdge(T u, T v)
   {
      adj[u].push_back(v);
      if (!directed)
      {
         adj[v].push_back(u);
      }
   }
   void printAdjList()
   {
      int len = adj.size();
      int l2;
      for (int i = 0; i < len; i++)
      {
         T key = adj.getkey(i);
         vector<T> links = adj.getval(i);

         cout << key << " -> ";
         l2 = links.size();
         for (int j = 0; j < l2; j++)
         {
            cout << links[j] << " ";
         }

         cout << endl;
      }
   }
   void BFS(Dictionary<T, bool> &visited, vector<T> &ans, T start)
   {
      queue<T> q;
      q.push(start);
      while (!q.empty())
      {
         T node = q.front();
         q.pop();
         visited[node] = true;
         ans.push_back(node);
         for (int i = 0; i < adj[node].size(); i++)
         {
            if (!visited[i])
            {
               q.push(adj[node][i]);
               visited[i] = true;
            }
         }
      }
   }
   vector<T> bfs()
   { /*
      * Front maango
      * queue mai push karo
      * visited mark
      * print
      * queue mai adjlist push karo
      * repeat
      */
      Dictionary<T, bool> visited;
      vector<T> ans;
      for (int i = 0; i < adj.size(); i++)
      {
         if (!visited[adj.getkey(i)])
            BFS(visited, ans, adj.getkey(i));
      }
      return ans;
   }
   void DFS(Dictionary<T, bool> &visited, vector<T> &ans, T start)
   {
      ans.push_back(start);
      visited[start] = true;
      for (int i = 0; i < adj[start].size(); i++)
      {
         T neighbor = adj[start][i];
         if (!visited[neighbor])
            DFS(visited, ans, neighbor);
      }
   }
   vector<T> dfs()
   {
      Dictionary<T, bool> visited;
      vector<T> ans;
      for (int i = 0; i < adj.size(); i++)
      {
         adj.getkey(i);
         if (!visited[adj.getkey(i)])
            DFS(visited, ans, adj.getkey(i));
      }
      return ans;
   }
   bool iscyclicBFS(Dictionary<T, bool> &visited, T start)
   {
      Dictionary<int, int> parent;
      parent[start] = -1;           
      visited[start] = true;
      queue<T> q;
      q.push(start);
      while (!q.empty())
      {
         T node = q.front();
         q.pop();
         for (int i = 0; i < adj[node].size(); i++)
         {
            T nieghbor = adj[node][i];
            if (!visited[nieghbor])
            {
               q.push(nieghbor);
               visited[nieghbor] = true;
               parent[nieghbor] = node;
            }
            else if (visited[nieghbor] == true && parent[node] != nieghbor)
            {
               return true;
            }
            
         }
      }
      return false;
   }
   bool cyclebfs()
   {
      Dictionary<T, bool> visited;
      for (int i = 0; i < adj.size(); i++)
      {
         if (!visited[adj.getkey(i)])
         {
            bool ans = iscyclicBFS(visited, adj.getkey(i));
            if (ans)
               return true;
         }
      }
      return false;
   }
};

int main()
{ 
   Graph<int> g;
   for (int i = 0; i < 5; i++)
      g.addvert(i);

   g.addEdge(0, 1);
   g.addEdge(1, 2);
   g.addEdge(2, 3);
   g.addEdge(3, 4);
   g.addEdge(4, 0); 
   g.printAdjList();
   // vector<int> ans = g.dfs();
   // vector<int> ans = g.bfs();

   // for (int &i : ans)
   // {
   //    cout << i << " ";
   // }
   // cout << endl;
   if (g.cyclebfs()) //undirected only
   {
      cout << "CYCLE FOUND" << endl;
   }
   else
   {
      cout << "CYCLE NOT FOUND" << endl;
   }
}