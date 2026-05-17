#include <bits/stdc++.h>
using namespace std;
bool dfs(int n ,int d,vector<int>adj[],vector<bool>vis){
    if(n==d){
        return true;
    }
    vis[n]=true;
    for(auto i :adj[n]){
        if(vis[i]==false){
            if(dfs(n,d,adj,vis)){
                return true;
            }
        }
    }
    return false;
}

bool bfs(int s,int d,vector<int>adj[],int v){
    vector<bool> vist(v,false);
    queue<int>q;
    vist[s]=true;
    q.push(s);
    while(q.empty()==false){
        int n = q.front();
        q.pop();
        if(n==d){
            return true;
        }
        for(int i :adj[n]){
            if(vist[i]==false){
                vist[i]=true;
                q.push(i);
            }
        }
    }
    return false;
}