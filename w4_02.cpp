#include<bits/stdc++.h>
using namespace std;
void Qs(vector<int>&a,int l,int r){
    if(l>=r){
        return;
    }
    int i =l,j=r;
    int pivot=a[l+(r-l)/2];
    while(i<=j){
        while(a[i]<pivot){
            i++;
        }
        while(a[j]>pivot){
            j--;
        }
        if(i<=j){
            swap(a[i++],a[j--]);
        }
    }
    Qs(a,l,j);
    Qs(a,i,r);

}
int main (){
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int>a={63, 42 ,223, 645, 652, 31 ,324 ,22 ,553 ,12 ,54 ,65, 86 ,46, 325};
    Qs(a,0,a.size()-1);
    for(int i:a){
        cout<<i<<" ";
    }
    return 0;
}