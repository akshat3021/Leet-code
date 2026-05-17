#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor]) {
            return true;
        }
    }
    recStack[node] = false; 
    return false;
}
bool hasCycle(int V, vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack))
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
    }
    if (hasCycle(V, adj)) {
        cout << "Yes Cycle Exists";
    } else {
        cout << "No Cycle Exists";
    }
    return 0;
}