#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> weight(n), value(n);
    for (int i = 0; i < n; i++) cin >> weight[i];
    for (int i = 0; i < n; i++) cin >> value[i];
    int W;
    cin >> W;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << "Maximum Value: " << dp[n][W] << endl;
    int w = W;
    cout << "Selected Items (weight, value):\n";
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "(" << weight[i - 1] << ", " << value[i - 1] << ")\n";
            w -= weight[i - 1];
        }
    }
    return 0;
}