#include<bits/stdc++.h> 
using namespace std;

struct item{
    int value , weight;
};
bool compare (item a, item b){
    double a1 = (double)a.value/a.weight;
    double b1 = (double)b.value/b.weight;
    return a1>b1;
}

double fk(vector<item>&items ,int cap){
    sort(items.begin(),items.end(),compare);
    double totalwt =0;
    for(int i =0 ;i<items.size();i++){
        if(items[i].weight<=cap){
            totalwt +=items[i].value;
            cap -=items[i].weight;
        }
        else{
            totalwt -=((double)items[i].value/items[i].weight)*cap;
            break;
        }
    }
    return totalwt;
}