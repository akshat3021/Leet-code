#include<bits/stdc++.h>
using namespace std;
void bs(vector<int>&a,int n){
    if(n==1){
        return;
    }
    int c=0;
    for(int i =0;i<n;i++){
        if(a[i]>a[i+1]){
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
            c++;
        }
    }
    if(c==0){
        return;
    }
    bs(a,n-1);
}
int main(){
    vector<int>a={34, 76 ,10 ,39 ,85 ,10 ,55};
    vector<int>b={30 ,55, 34 ,72 ,10 ,34 ,10 ,89 ,11 ,30 ,69 ,51};
    bs(a,a.size());
    bs(b,b.size());
    int i =0,j=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]==b[j]){
            cout<<a[i]<<" ";
            i++,j++;
        }
        else if(a[i]<b[j]){
            i++;
        }
        else {
            j++;
        }
    }
    return 0;

}