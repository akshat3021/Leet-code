#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    int N;
    cin >> N;
    vector<long long> dp(N + 1, 0);
    dp[0] = 1; 
    for (int coin : coins) {
        for (int i = coin; i <= N; i++) {
            dp[i] += dp[i - coin];
        }
    }
    cout << "Number of ways: " << dp[N];
    return 0;
}