#include <bits/stdc++.h>
using namespace std;
void printPath(int node, vector<int>& parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}
void dijkstra(int V, vector<vector<pair<int,int>>>& adj, int source) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto &edge : adj[node]) {
            int neighbor = edge.first;
            int weight = edge.second;
            if (dist[node] + weight < dist[neighbor]) {
                dist[neighbor] = dist[node] + weight;
                parent[neighbor] = node;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << "From Node " << i << " to Akshay's House (" << source << "):\n";

        if (dist[i] == INT_MAX) {
            cout << "No Path Exists\n";
        } else {
            cout << "Distance: " << dist[i] << "\nPath: ";
            printPath(i, parent);
            cout << endl;
        }
        cout << "-------------------\n";
    }
}
int main() {
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int akshayHouse;
    cin >> akshayHouse; 
    dijkstra(V, adj, akshayHouse);
    return 0;
}