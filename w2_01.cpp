#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main(){
    vector<int>a= {1,2,3,4,5,6,7,2,4,5};
    int k;
    cout<<"Enter key : ";
    cin>>k;

    unordered_map<int,int> m;
    for(int x:a){
        m[x]++;
    }
    int c=0;
    for(auto& p:m){
        if(p.first==k){
            cout<<"Key is present"<<endl<<"Frequency of element is:"<<p.second;
            break;
        }
        else{
            c++;
        }
    }
    if(c==m.size()){
        cout<<"Key is not present";
    }
    return 0;
}