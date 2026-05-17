#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int candidate = -1, count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = arr[i];
            count = 1;
        } else if (arr[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    count = 0;
    for (int x : arr) {
        if (x == candidate) count++;
    }
    if (count > n / 2)
        cout << "yes\n";
    else
        cout << "no\n";
    sort(arr.begin(), arr.end());
    if (n % 2 == 1) {
        cout << arr[n / 2];
    } else {
        double median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        cout << median;
    }
    return 0;
}