#include <bits/stdc++.h>
using namespace std;

int primsMST(int V, vector<vector<pair<int,int>>>& adj) {

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<bool> visited(V, false);
    int totalWeight = 0;

    pq.push({0, 0});          // start from vertex 0, weight 0

    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;   // already in MST, skip

        visited[u] = true;          // add to MST
        totalWeight += wt;          // add edge weight

        for (auto [v, w] : adj[u]) {
            if (!visited[v])
                pq.push({w, v});
        }
    }
    return totalWeight;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    // Build adjacency list from adjacency matrix
    vector<vector<pair<int,int>>> adj(V);

    cout << "Enter adjacency matrix (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            int w;
            cin >> w;
            if (w != 0)                        // 0 means no edge
                adj[i].push_back({j, w});
        }
    }

    cout << "Minimum Spanning Weight: " << primsMST(V, adj) << "\n";
    return 0;
}