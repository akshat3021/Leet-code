#include <bits/stdc++.h>
using namespace std;

int prismMst(vector<vector<int>> &adj){
    int V = adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<bool>vist(V,false);
    int tw =0;
    pq.emplace(0,0);
    while(!pq.empty()){
        auto w = pq.top().first;
        auto u = pq.top().second;
        pq.pop();
        if(vist[u]) continue;

        vist[u]= true;
        tw+=w;
         for(auto i :adj[u]){
            auto v = i.first;
            auto w = i.second;
            if(!vist[v]) 
            pq.emplace(w,v);
         }
    }
    return tw;
}