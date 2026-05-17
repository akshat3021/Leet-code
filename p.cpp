#include<bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>&adj, vector<int>&vis, vector<int>&path)
{
    vis[u] = 1;
    path[u] = 1;

    for(int v : adj[u])
    {
        if(!vis[v] && dfs(v, adj, vis, path))
            return true;

        if(path[v])
            return true;
    }

    path[u] = 0;
    return false;
}

int main()
{
    int n = 4;

    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> vis(n,0), path(n,0);

    for(int i=0;i<n;i++)
    {
        if(!vis[i] && dfs(i,adj,vis,path))
        {
            cout<<"Cycle exists";
            return 0;
        }
    }

    cout<<"No cycle";
}