#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int>&a){
if(a.size()<=1){
    return;
}
int mid=a.size()/2;
vector<int> left(a.begin(),a.begin()+mid);
vector<int> right(a.begin()+mid,a.end());
merge(left.begin(),left.end(),right.begin(),right.end(),a.begin());
}