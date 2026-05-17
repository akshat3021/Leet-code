#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int dest, vector<vector<int>>& adj, vector<bool>& visited) {
    if (node == dest) return true;
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, dest, adj, visited))
                return true;
        }
    }
    return false;
}
int main() {
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source, dest;
    cin >> source >> dest;
    vector<bool> visited(V, false);
    if (dfs(source, dest, adj, visited)) {
        cout << "Yes Path Exists";
    } else {
        cout << "No Such Path Exists";
    }
    return 0;
}