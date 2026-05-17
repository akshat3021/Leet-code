#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V , vector<vector<pair<int , int>>> &adj,int src){

    vector<int> dist (V,INT_MAX);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    dist[src]=0;
    pq.push({0,src});

    while(!pq.empty()){
        int currDist=pq.top().first;
        int u =pq.top().second;
        pq.pop();
        for(auto &edge:adj[u]){
            int weight = edge.second;
            int v = edge.first;

            if(currDist+weight <dist[v]){
                dist[v]=currDist+weight;
                pq.push({dist[v],v});
            }

        }
    }
}