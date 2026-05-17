#include <bits/stdc++.h>
using namespace std;
vector<int> BellmanFord(int V , vector<vector<int>>& edges ,int src){
    vector<int>distance (V,1e8);
    distance[src] =0;

    for(int i =0 ; i<V;i++ ){
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(distance [u]!=1e8 &&distance[u]+wt <distance[v]){
                if(i==V-1){
                    return {-1};
                }
                distance[v]= distance[u]+wt;
            }
        }
    }
    return distance;
}

int main (){
    int V,e;
    cout<<"Enter no if edges: ";
    cin>>V;
    cout << "Enter number of edges: ";
    cin >> e;
    vector<vector<int>> edges;
    for(int i =0 ;i<e;i++){
        int u , v ,wt;
        cin>>u;
        cin>>v;
        cin>>wt;
        edges.push_back({u,v,wt});
    }
    int src ;
    cout<<"Enter source vertex: ";
    cin>>src;

    vector<int>sp =BellmanFord(V,edges,src);
    if(sp.size()==1&&sp[0]==-1){
        cout<<"Neative cycle exist";
    }else {
    cout<<"Shortest path from src to all vertx:";
    for(auto a:sp){
        cout<<a<<" ";
    }
}
    return 0;

}