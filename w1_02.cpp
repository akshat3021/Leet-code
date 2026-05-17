#include<bits/stdc++.h>
using namespace std;
pair<int,int> bs(vector<int>&a,int l,int h,int k,int c){
    if(l>h){
        return{-1,c};
    }
    c++;
   int mid =l+(h-l)/2;
   if(a[mid]==k){
    return {mid,c};
   }
   if(a[mid]>k){
    return bs(a,l,mid-1,k,c);
   }
   else{
    return bs(a,mid+1,h,k,c);
   }

}
int main(){
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int> a = {1, 2, 3, 4, 6, 7, 8, 9};
    int key=8,c=0;
    pair<int ,int> result=bs(a,0,a.size()-1, key,0);
    if(result.first==-1){
        cout<<"Key not present";
    }
    else{
        cout <<"key is found at index: "<<result.first<<endl;
        cout <<"number of comparesion: "<<result.second;
    }
    return 0;
}