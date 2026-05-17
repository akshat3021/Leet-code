#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v, w;
};
int findParent(int x, vector<int>& parent) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x], parent);
}
void unionSet(int u, int v, vector<int>& parent) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    parent[pu] = pv;
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges(E);
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w > b.w;
    });
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;
    int totalCost = 0;
    int count = 0;
    for (auto e : edges) {
        int pu = findParent(e.u, parent);
        int pv = findParent(e.v, parent);
        if (pu != pv) {
            unionSet(pu, pv, parent);
            totalCost += e.w;
            count++;
            if (count == V - 1)
                break;
        }
    }
    cout << "Maximum Spanning Weight: " << totalCost;
    return 0;
}