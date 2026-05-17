#include<bits/stdc++.h>
using namespace std;
void ms(vector<int >&a){
    if(a.size()<=1){
        return;
    }
    int mid = a.size()/2;
    vector<int>left(a.begin(),a.begin()+mid);
    vector<int>right(a.begin()+mid,a.end());
    ms(left);
    ms(right);
    merge(left.begin(),left.end(),right.begin(),right.end(),a.begin());
}
int main (){
    cout<<"Akshat Aswal"<<endl<<"G1"<<endl<<"Roll NO : 09"<<endl;
    vector<int>a={43 ,64, 13 ,78 ,864, 346 ,786 ,456 ,21 ,19, 8 ,434 ,76 ,270 ,601 };
    ms(a);
    int k =3;
    for(int i:a){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Kth smallest :"<<a[k-1]<<endl;
    cout<<"Kth largest :"<<a[(a.size())-k];
return 0;
}