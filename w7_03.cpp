#include <bits/stdc++.h>
using namespace std;
int main() {
    int V;
    cin >> V;
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < V; i++) {
        int u, v, w;
        cin >> u >> v >> w;  
        adj[u].push_back({v, w});
    }
    int source, dest, k;
    cin >> source >> dest;
    cin >> k;
    const int INF = INT_MAX;
    vector<vector<int>> dp(k + 1, vector<int>(V, INF));
    dp[0][source] = 0;
    for (int e = 1; e <= k; e++) {
        for (int u = 0; u < V; u++) {
            if (dp[e - 1][u] != INF) {
                for (auto &edge : adj[u]) {
                    int v = edge.first;
                    int w = edge.second;

                    if (dp[e - 1][u] + w < dp[e][v]) {
                        dp[e][v] = dp[e - 1][u] + w;
                    }
                }
            }
        }
    }
    if (dp[k][dest] == INF) {
        cout << "no path of length k is available";
    } else {
        cout << dp[k][dest];
    }
    return 0;
}