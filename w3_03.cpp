#include<bits/stdc++.h>
using namespace std;
int main (){
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int> a ={28 ,52 ,83 ,14 ,75,28};
    map<int ,int> m;
    for(int i:a){
        m[i]++;
    }
    bool b = false;
    for(auto y:m){
        if(y.second>1){
        b=true;
        }
    }
    if(b==true){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}