#include <bits/stdc++.h>
using namespace std;
bool isBipartite(int V, vector<vector<int>>& adj) {
    vector<int> color(V, -1); 
    for (int start = 0; start < V; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    }
                    else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
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
    if (isBipartite(V, adj)) {
        cout << "Yes Bipartite";
    } else {
        cout << "Not Bipartite";
    }
    return 0;
}