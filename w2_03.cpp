#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> a={1 ,51 ,84, 21 ,31};
    int c=0;
    for(int i =0;i<a.size()-2;i++){
        int j=(a.size()-1);
        while(i<j){
            int diff=a[i]-a[j];
            if(diff==20){
                c++;
            }
            else{
                j--;
            }
        }
    }
    cout<<"No of pairs :"<<c;
    return 0;
}