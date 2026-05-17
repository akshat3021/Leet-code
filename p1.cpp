#include <bits/stdc++.h>
using namespace std;
// Code for Linear search
int ls(vector <int>&a,int key){
for(int i=0;i<a.size();i++){
    if(a[i]==key){
        return i;
    }
}
return -1;
}
//code for binary search
int bs(vector<int>a,int l,int h,int key ){
    if(l>h){
        return -1;
    }
    int mid = l+(h-l)/2;
    if(a[mid]==key){
        return mid ;
    }
    else if(a[mid]<key){
        return(a,mid+1,h,key);
    }
    else{
        return (a,l,mid-1,key);
    }
}
//code for insertion sort
void inserttion(vector<int>&a){
    int n = a.size();
    for(int  i=1 ;i<n ;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0&&a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
// Dfs 
bool dfs(int s ,int d,vector<int>adj[],vector<bool>&vist ){
    if(s==d){
        return true;
    }
    vist[s]= true;
    for(auto i : adj[s]){
        if(vist[i]==false){
            if(dfs(i,d,adj,vist)){
                return true;
            }
        }
    }
    return false;
}
//code For BSF
bool bfs(int s,int d ,vector<int>adj[],int v){
    vector<bool> vist(v,false);
    queue<int>q;
    vist[s]=true;
    q.push(s);
    while(q.empty()==false){
        int n = q.front();
        q.pop();
        if(n==d){
            return true;
        }
        for(int i:adj[n]){
            if(vist[i]==false){
                vist[i]=true;
                q.push(i);
            }
        }
    }
return false;
}
