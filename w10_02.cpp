#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> time(n), deadline(n);
    for (int i = 0; i < n; i++) cin >> time[i];
    for (int i = 0; i < n; i++) cin >> deadline[i];
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b) {return deadline[a] < deadline[b];});
    priority_queue<pair<int,int>> pq; 
    int currentTime = 0;
    for (int i : idx) {
        currentTime += time[i];
        pq.push({time[i], i});
        if (currentTime > deadline[i]) {
            currentTime -= pq.top().first;
            pq.pop();
        }
    }
    vector<int> selected;
    while (!pq.empty()) {
        selected.push_back(pq.top().second);
        pq.pop();
    }
    cout << "Maximum Tasks: " << selected.size() << endl;
    cout << "Selected Tasks (index):\n";
    for (int i : selected) {
        cout << i << " ";
    }
    return 0;
}