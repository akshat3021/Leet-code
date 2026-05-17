#include<bits/stdc++.h>
using namespace std;
void bubble_Sort(vector<int>&a,int n){
    if(n==0){
        return;
    }
    int c =0;
    for(int i =0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int temp = a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            c++;
        }
    }
    if(c==0){
        return;
    }
    bubble_Sort(a,n-1);
}

void selection_sort(vector<int>&v){
    int n = v.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j =i+1;j<n;j++){
            if(v[i]>v[j]){
                min =j;
            }
        }
          swap(v[i],v[min]);
    }

}


int main (){
    int n ;
    cout<<"enter size of arrya";
    cin>>n;
    vector<int> a(n);
    for(int i =0 ;i<n;i++){
        cin>>a[i];
    }
    cout<<endl<<"arrya before sorting";
    for(int i:a){
        cout<<i;
    }
    bubble_Sort(a,n);
     cout<<endl<<"arrya after sorting";
    for(int i:a){
        cout<<i;
    }
    return 0;
}