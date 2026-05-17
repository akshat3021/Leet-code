#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int> start(N), finish(N);
    for (int i = 0; i < N; i++) cin >> start[i];
    for (int i = 0; i < N; i++) cin >> finish[i];
    vector<int> idx(N);
    for (int i = 0; i < N; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int a, int b) { return finish[a] < finish[b];});
    vector<int> selected;
    selected.push_back(idx[0]);
    int lastFinish = finish[idx[0]];
    for (int i = 1; i < N; i++) {
        if (start[idx[i]] >= lastFinish) {
            selected.push_back(idx[i]);
            lastFinish = finish[idx[i]];
        }
    }
    cout << "Maximum Activities: " << selected.size() << endl;
    cout << "Selected Activities (start, finish):\n";
    for (int i : selected) {
        cout << "(" << start[i] << ", " << finish[i] << ")\n";
    }
    return 0;
}