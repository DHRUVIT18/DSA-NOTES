#include<bits/stdc++.h>
using namespace::std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    unordered_map<int,vector<pair<int,int>>>adj;
    //unordered map stores --> x->{y,dist};
    for(auto it:vec){
        adj[it[0]].push_back({it[1],it[2]});
         adj[it[1]].push_back({it[0],it[2]});
    }
    vector<int>dis(vertices,INT_MAX);
    //create min heap and store primary element as dist;
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>q;
    dis[0]=0;
    q.push({0,source});
    while(!q.empty()){
        auto  curr=q.top();
        q.pop();
        int dist=curr[0];
        int node=curr[1];
        for(auto it:adj[node]){
            int nex=it.first;
            int nexdist=it.second;
            if(dis[nex]>dist+nexdist){
                dis[nex]=dist+nexdist;
                q.push({dis[nex],nex});
            }
        }
    }
    return dis;
}

int main(){

}