#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
void printPath(int node, vector<int>& parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}
void bellmanFord(int V, vector<Edge>& edges, int source) {
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);
    dist[source] = 0;
    for (int i = 0; i < V - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }
    for (auto &e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative weight cycle detected\n";
            return;
        }
    }
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " to Source " << source << ":\n";

        if (dist[i] == INT_MAX) {
            cout << "No Path Exists\n";
        } else {
            cout << "Distance: " << dist[i] << "\nPath: ";
            int curr = i;
            while (curr != -1) {
                cout << curr << " ";
                curr = parent[curr];
            }
            cout << endl;
        }
        cout << "------------------\n";
    }
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int source;
    cin >> source;
    bellmanFord(V, edges, source);
    return 0;
}