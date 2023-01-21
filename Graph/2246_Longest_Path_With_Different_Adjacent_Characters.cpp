class Solution {
public:
    int dist[100005];
    int res=1;
    unordered_map<int,vector<int>>adj;
    void dfs(int node,string &s){
        dist[node]=1;
        for(auto i:adj[node]){
            dfs(i,s);
            if(s[node]!=s[i]){
                res=max(res,dist[node]+dist[i]);
                dist[node]=max(dist[node],1+dist[i]);
            }
        }
    }
    int longestPath(vector<int>& parent, string s) {
        //s1 building input
        for(int i=1;i<parent.size();i++){
            adj[parent[i]].push_back(i);       
        }
        //s2 precomputation
        dfs(0,s);
        
        
        //s3 returning res
        return res;
    }
};
// [ 0,1,2,3,4,5]
// [-1,0,0,1,1,2]