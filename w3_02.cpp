#include<bits/stdc++.h>
using namespace std;
pair<int ,int> Ss(vector<int>&a){
    int c=0,s=0;
    int n = a.size();
    for(int i = 0;i<n;i++){
        int min =i;
        for(int j=i+1;j<n;j++){
            c++;
            if(a[min]>a[j]){
                min = j;
            }
        }
        if(min!=i){
        swap(a[i],a[min]);
        s++;
    }
    }
    return{c,s};
}
int main(){
    vector<int>a={54, 65, 34, 76 ,78 ,97, 46, 32 ,51 ,21};
    pair<int ,int> ans=Ss(a);
    for(int i :a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"No of comprasions: "<<ans.first<<endl<<"no of swaps: "<<ans.second;
    return 0;
}
