//Topological sort using BFS
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addedge(vector<int> adj[], int u,int v)
{
    adj[u].push_back(v);
}

void topologicalsort(vector<int> adj[], int V)
{
    //Creation of a vector indegree to store the indegrees of all the vertices
    vector<int> indegree(V,0);
    for(int i =0;i<V;i++)
    {
        for(int x: adj[i])
        indegree[x]++;
    }
    //Creation of a queue
    queue<int> q;
    for(int i =0;i<V;i++)
    {
        // adding all the vertices with indegree=0 to the queue
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int  u=q.front();
        q.pop();
        cout<<u<<" "; // prints in topological sort
        for(int i : adj[u]) //checking every adjacent vertex of u
        {
            indegree[i]--; // reducing the indegree of vetrex as to reduce the dependency since the last job was completed
            if(indegree[i]==0) // if indegree of a vertex is 0 then put it into the queue
            q.push(i);
        }
    }
}
int main()
{
    int V =5;
    vector <int> adj[V];
    addedge(adj,0,2);
    addedge(adj,0,3);
    addedge(adj,1,3);
    addedge(adj,1,4);
    addedge(adj,2,3);
    topologicalsort(adj,V);
}