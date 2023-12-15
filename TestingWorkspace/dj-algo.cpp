#include "Headers.h"
#include "Dictionary.h"
#include "Minheap.cpp"
using namespace std;
template <class T>
class WGraph
{
public:
   Dictionary<T, vector<Pair<T, int>>> adj;
   bool directed;

   WGraph(bool directed = false)
   {
      this->directed = directed;
   }
   void addvert(T u)
   {
      adj.add(u, vector<T>());
   }
   void addEdge(T u, T v, int w)
   {
      Pair<T, int> p(v, w);
      adj[u].push_back(p);
      if (!directed)
      {
         p.first = u;
         p.second = w;
         adj[v].push_back(p);
      }
   }

   void printAdjList()
   {
      int len = adj.size();
      int l2;
      for (int i = 0; i < len; i++)
      {
         T key = adj.getkey(i);
         vector<Pair<T, int>> links = adj.getval(i);

         cout << key << " -> ";
         l2 = links.size();
         for (int j = 0; j < l2; j++)
         {
            cout << " (" << links[j].first << "," << links[j].second << ") ,";
         }
         cout << "\b "; // remove last comma
         cout << endl;
      }
   }
   vector<int> dj_algo(T start)
   {
      heap min(adj.size());
      vector<int> dists;
      for (int i = 0; i < adj.size(); i++)
      {
         dists.push_back(INT_MAX);
      }
      dists[start] = 0;
      min.insert(make_pair(start, 0));
      while (!min.isEmpty())
      {
         pair<int, int> front = min.getmin();
         int topnode = front.first;
         int nodeDist = front.second;
         min.deletemin();
         for (int i = 0; i < adj[topnode].size(); i++)
         {
            Pair<T, int> neighbor = adj[topnode][i];
            if (nodeDist + neighbor.second < dists[neighbor.first])
            {
               pair<int, int> find = make_pair(neighbor.first, dists[neighbor.first]);
               // min.deleteentry(find);
               dists[neighbor.first] = nodeDist + neighbor.second;
               find = make_pair(neighbor.first, dists[neighbor.first]);
               min.insert(find);
            }
         }
      }
      return dists;
   }
};

int main()
{
   WGraph<int> g;
   g.addEdge(0, 1, 7);
   g.addEdge(0, 2, 1);
   g.addEdge(0, 3, 2);
   g.addEdge(1, 2, 3);
   g.addEdge(1, 3, 5);
   g.addEdge(1, 4, 1);
   g.addEdge(3, 4, 7);

   g.printAdjList();
   vector<int> l = g.dj_algo(0);
   for (int i = 0; i < l.size(); i++)
   {
      cout << l[i] << " ";
   }
   cout << endl;
}