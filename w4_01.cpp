#include<bits/stdc++.h>
using namespace std;
int c=0;
int ms(vector<int>&a){
    int n =a.size();
    if(n<=1){
        return c;
    }
    c++;
    int mid = n/2;
    vector<int>l(a.begin(),a.begin()+mid);
    vector<int>r(a.begin()+mid,a.end());
    ms(l);
    ms(r);
    merge(l.begin(),l.end(),r.begin(),r.end(),a.begin());
    return c;
}
int main (){cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int>a={63 ,42 ,223 ,645 ,652 ,31 ,324 ,22 ,553, 12 ,54, 65, 86 ,46 ,325};
    int c =ms(a);
    for(int i :a){
        cout<<i<<" ";
    }
    cout<<endl<<"number of comparision"<<c;
    return 0;
}