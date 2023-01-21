class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),-1));
        queue<vector<int>>q;
        q.push({0,0,0,k});
        while(!q.empty())
        {
            auto curr=q.front();q.pop();
            int x=curr[0];
            int y=curr[1];
            if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size()){
                continue;
            }
            if(x==grid.size()-1 and y==grid[0].size()-1){
                return curr[2];
            }
            
            if(grid[x][y]==1){
                if(curr[3]>0)
                    curr[3]--;
                else
                    continue;
                
            }
            
            if(vis[x][y]!=-1 and vis[x][y]>=curr[3]){
                continue;
            }
            vis[x][y]=curr[3];
            
            q.push({x+1,y,curr[2]+1,curr[3]});
            q.push({x-1,y,curr[2]+1,curr[3]});
            q.push({x,y+1,curr[2]+1,curr[3]});
            q.push({x,y-1,curr[2]+1,curr[3]});

            
            
        }
        return -1;
    }
};