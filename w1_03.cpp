#include<bits/stdc++.h>
using namespace std;
void searchElement(vector<int>& arr, int n, int key) {
    int comparisons = 0;
    comparisons++;
    if (arr[0] == key) {
        cout << "Present " << comparisons << endl;
        return;
    }
    int i = 1;
    while (i < n && arr[i] <= key) {
        comparisons++;
        i = i * 2;
    }
    int left = i / 2;
    int right = min(i, n - 1);
    for (int j = left; j <= right; j++) {
        comparisons++;
        if (arr[j] == key) {
            cout << "Present " << comparisons << endl;
            return;
        }
    }
    cout << "Not Present " << comparisons << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int key;
        cin >> key;
        searchElement(arr, n, key);
    }
    return 0;
}