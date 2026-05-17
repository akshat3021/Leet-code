#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    unordered_map<int, pair<int, int>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int prod = arr[i] * arr[j];
            if (mp.find(prod) != mp.end()) {
                auto prev = mp[prod];
                int a = prev.first;
                int b = prev.second;
                if (a != i && a != j && b != i && b != j) {
                    cout << "(" << arr[a] << ", " << arr[b] << ")\n";
                    cout << "(" << arr[i] << ", " << arr[j] << ")\n";
                    return 0;
                }
            } else {
                mp[prod] = {i, j};
            }
        }
    }
    cout << "No such pairs found";
    return 0;
}