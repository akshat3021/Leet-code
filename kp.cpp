#include <bits/stdc++.h>
using namespace std;
 int knap(vector<int>&values,vector<int>&weights,int cap){
    int n = values.size();
    vector<vector<int>>dp(n+1,vector<int>(cap+1,0));
    for(int i =1;i<=n;i++){
        for(int w =1;w<=cap;w++){
            if(weights[i-1]<=w){
                dp[i][w]=max(values[i-1]+dp[i-1][w-weights[i-1]],dp[i-1][w]);
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][cap];
 }