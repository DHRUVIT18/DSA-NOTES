class Solution {
public:
    vector<int>adj[100005];
    vector<bool>apple;
    pair<int,int>dfs(int node,int p){
        pair<int,int>v={0,apple[node]};
        for(auto i:adj[node]){
            if(i!=p){
                auto x=dfs(i,node);
                v.first+=(2+x.first)*x.second;
                v.second|=x.second;
            }
        }
        return v;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        apple=hasApple;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

        }
        int res=dfs(0,0).first;
        return res;
    }
};