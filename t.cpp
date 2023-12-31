#include "Headers.h"
int main()
{
    unordered_map <int,vector<int>> baka;
    cout <<"enter num of edges"<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter edge"<<endl;
        int a,b;
        cin>>a>>b;
        baka[a].push_back(b);
        // baka[b].push_back(a); //uncomment for undirected graph
    }
    cout<<"The graph is as follows"<<endl;
    for(auto i:baka)
    {
        cout<<i.first<<" : ";
        for(auto j:i.second)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}