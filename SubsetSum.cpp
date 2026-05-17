#include <bits/stdc++.h>
using namespace std;
 bool subsetSum (vector<int>arr,int sum){
    int n = arr.size();
    vector<bool> prev(sum+1 ,false) ,curr(sum+1);

    prev[0]=true;

    for(int i=1;i<=n;i++){
        for(int j =0 ;j<=sum;j++){
            if(j<arr[i]){
                curr[j]=prev[j];
            }
            else
            {
                curr[j]= (prev[j]||prev[j-arr[i-1]]);
            }
        }
        prev= curr;
    }
    return prev[sum];
 }
 int main (){
    vector<int> arr ={1,2,3,4,5};
    int sum = 5;
   if(subsetSum(arr,sum)){
    cout<<"True";
   }else{
    cout<<"False";
   }
    return 0;
 }