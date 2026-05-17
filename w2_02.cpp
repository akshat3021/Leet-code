#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>a={24 ,28 ,48, 71, 86, 89, 92, 120, 194, 201};
    for(int k =(a.size())-1 ;k>=0;k--){
        int i=0,j=k-1;
        while(i<j){
            int sum = a[i]+a[j];
            if(sum==a[k]){
                cout << "Found indices: "
                     << i << ", "
                     << j << ", "
                     << k << endl;
                return 0;
            }
            else if(sum<a[k]){
                i++;
            }
            else{
                j--;
            }
        }  
}
 cout << "No such triplet found";
return 0;
}