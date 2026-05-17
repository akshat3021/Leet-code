#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> files(n);
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : files) {
        pq.push(x);
    }
    int totalCost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int cost = a + b;
        totalCost += cost;
        pq.push(cost);
    }
    cout << "Minimum Computation Cost: " << totalCost;
    return 0;
}