#include <bits/stdc++.h>
using namespace std;
int primMST(int V, vector<vector<pair<int,int>>>& adj) {
    vector<bool> inMST(V, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 0}); 
    int totalCost = 0;
    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (inMST[node]) continue;
        inMST[node] = true;
        totalCost += weight;
        for (auto &edge : adj[node]) {
            int neighbor = edge.first;
            int w = edge.second;

            if (!inMST[neighbor]) {
                pq.push({w, neighbor});
            }
        }
    }
    return totalCost;
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int cost = primMST(V, adj);
    cout << "Minimum Cost to Connect Cities: " << cost;
    return 0;
}