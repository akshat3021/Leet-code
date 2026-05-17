#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& value, vector<int>& weight,int capacity) {

    int n = value.size();

    vector<vector<int>> dp(n + 1,vector<int>(capacity + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= capacity; w++) {
            if(weight[i - 1] <= w) {
                dp[i][w] =
                max(value[i - 1] + dp[i - 1][w - weight[i - 1]],dp[i - 1][w]);
            }
            else { 
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main() {
    vector<int> val =  {1 ,2 ,5 ,9 ,4};
    vector<int> wt = {2 ,3 ,3 ,4 ,6} ;
    int capacity = 10;
    
    cout << knapsack(val, wt, capacity) << endl;
    
    return 0;
}