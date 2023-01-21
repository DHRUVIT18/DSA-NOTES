class Solution {
public:
   int func(vector<vector<int>>& grid,vector<vector<vector<int>>>&dp,
            int row1,int col1,int row2,int col2){
       int n=grid.size();
       if(row1>=n or row2>=n or col1>=n or col2>=n or grid[row1][col1]==-1 
          or grid[row2][col2]==-1){
           return -1e8;
       }
       if(row1==n-1 and col1==n-1){
           return grid[row1][col1];
       }
       if(dp[row1][col1][col2]!=-1){
           return dp[row1][col1][col2];
       }
       int currsum=0;
       
       if(row1!=row2){
           
           currsum=grid[row1][col1]+grid[row2][col2];
       }else{
           
           currsum=grid[row1][col1];
       }
       int maxcherries=-1e8;
       int downdown=func(grid,dp,row1+1,col1,row2+1,col2);
       int downright=func(grid,dp,row1+1,col1,row2,col2+1);
       int rightright=func(grid,dp,row1,col1+1,row2,col2+1);
       int rightdown=func(grid,dp,row1,col1+1,row2+1,col2);
       maxcherries=max(downdown,max(downright,max(rightright,rightdown)));
       
       return dp[row1][col1][col2]=maxcherries+currsum;
       
       
   }
    
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        int cherries=func(grid,dp,0,0,0,0);
        return cherries<=0?0:cherries;
    }
};