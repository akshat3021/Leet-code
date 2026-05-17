#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }
    if (totalSum % 2 != 0) {
        cout << "no";
        return 0;
    }
    int target = totalSum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int num : arr) {
        for (int i = target; i >= num; i--) {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    if (dp[target])
        cout << "yes";
    else
        cout << "no";

    return 0;
}