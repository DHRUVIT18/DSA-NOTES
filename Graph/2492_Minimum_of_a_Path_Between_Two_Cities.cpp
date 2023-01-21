class Solution {
public:
    int bfs(vector<vector<vector<int>>>&graph,int u,int n){
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(u);
        int res=INT_MAX;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            vis[curr]=true;
            for(auto &v:graph[curr]){
                if(!vis[v[0]]){
                    res=min(res,v[1]);
                    q.push(v[0]);
                }
            }
        }
        return res;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>graph(n);
        for(auto i:roads){
            graph[i[0]-1].push_back({i[1]-1,i[2]});
            graph[i[1]-1].push_back({i[0]-1,i[2]});

        }
        return bfs(graph,0,n-1);
    }
};