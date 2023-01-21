class Solution {
public:
    int dp[201][201];
    int f(vector<vector<int>>&A,int i=0,int j=0){
        int n=A.size(),m=A[0].size();
        if(i==n or j==m)return  1e8;
        
        if(i==n-1 and j==m-1){
            return (A[i][j]<=0)?-A[i][j]+1:1;
            
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int right=f(A,i,j+1);
        int down=f(A,i+1,j);
        
        int health=min(right,down)-A[i][j];
        
        
        return dp[i][j]= (health<=0)?1:health;
    }
    
    int calculateMinimumHP(vector<vector<int>>& A) {
        memset(dp,-1,sizeof(dp));
        return f(A);
    }
};