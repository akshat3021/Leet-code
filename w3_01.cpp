#include<bits/stdc++.h>
using namespace std;
int insertion(vector<int>&a){
    int n = a.size();
    int c=0;
    for(int i = 1;i<n;i++){
        int key =a[i];
        int j =i-1;
        while(j>=0 && a[j]>key){
            c++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    return c;
}

int main (){
    vector<int>a = {-23, 65, -31 ,76 ,46 ,89, 45, 32};
    int c =insertion(a);
    for(int x: a){
        cout<<x<<" ";
    }
    cout<<endl<<"Total no of comparsion are : "<<c;
    return 0;
}