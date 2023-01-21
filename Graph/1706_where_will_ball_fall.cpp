//1706 where will ball fall


class Solution {
public:
     bool valid(int rsize,int csize,int r,int c){
        if(rsize<=r||csize<=c||c<0||r<0)return false;
        return true;
    }
   int dfs(int i,int j,vector<vector<int>>&grid){
       if(i==grid.size())return j;
       
       if(valid(grid.size(),grid[0].size(),i,j)){
           
       
       if(grid[i][j]==1){
           if(valid(grid.size(),grid[0].size(),i,j+1) and grid[i][j+1]==1){
               return dfs(i+1,j+1,grid);
           }
       }else{
           if(valid(grid.size(),grid[0].size(),i,j-1) and grid[i][j-1]==-1){
               return dfs(i+1,j-1,grid);
           }
       }
       }
       return -1;
    }
    
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans(grid[0].size());
        for(int i=0;i<grid[0].size();i++){
            ans[i]=dfs(0,i,grid);
        }
        return ans;
    }
};