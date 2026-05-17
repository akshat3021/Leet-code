#include <bits/stdc++.h>
using namespace std;
pair<int ,int> linear_search(vector<int>&a,int key){
    int compare =0;
    for(int i =0 ;i<a.size();i++){
         compare++;
        if(a[i]==key){
            return {i,compare};
    }
}
return {-1,compare};
}

int main(){
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key=7;
    pair<int ,int> result=linear_search(a, key);
    if(result.first==-1){
        cout<<"Key not present";
    }
    else{
        cout <<"key is found at index: "<<result.first;
        cout <<"nnumber of comparesion: "<<result.second;
    }
    return 0;
}