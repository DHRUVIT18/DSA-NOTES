#include<bits/stdc++.h>

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int>dist(n+1,1e9);
    dist[src]=0;
    //iterate n-1 to find shortest path in cyclic graph with negative edges where dijkstra not work
    //iterate again 1 time and find if the weight is relaxed? if yes then there is negative edge cycle present.
    for(int i=1;i<=n;i++){
       for(auto it:edges){
           if(dist[it[0]]!=1e9 and dist[it[0]]+it[2]<dist[it[1]]){
               dist[it[1]]=dist[it[0]]+it[2];
           }
       }
    }
    return dist[dest];

}