class Solution {
public:
    long long res=0;
    
    unordered_map<int,vector<int>>adj;
    long long dfs(int node,vector<int>&vis,int seats){
        vis[node]=1;
        long long cnt=1;
        for(int i=0;i<adj[node].size();i++){
            int curr=adj[node][i];
            if(!vis[curr]){
                cnt+=dfs(curr,vis,seats);
            }
        }
        long long x=cnt/seats;
        if(cnt%seats)x++;
        if(node!=0)res+=x;
        
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        //s1
        int n=roads.size();
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n+1,0);
        
        //s2
        dfs(0,vis,seats);
        
        return res;
    }
};