class Solution {
public:
//memoisation giving tle
//     int dp[1001][1001];
//     int f(int i,int j,string s, string t){
//         if(i==0){
//             int sum=0;
//             for(int k=0;k<j;k++){
//                 sum+=t[k]-'a'+97;
//             }
//             return sum;
//         }
//         if(j==0){
//              int sum=0;
//             for(int k=0;k<i;k++){
//                 sum+=s[k]-'a'+97;
//             }
//             return sum;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(s[i-1]==t[j-1]){
//             return dp[i][j]= f(i-1,j-1,s,t);
//         }
//         int ds=s[i-1]-'a'+97+f(i-1,j,s,t);
//         int dt=t[j-1]-'a'+97+f(i,j-1,s,t);
     
//         return dp[i][j]= min({ds,dt});
//     }
    
//     int minimumDeleteSum(string s, string t) {
//         int n=s.size();
//         int m=t.size();
//         memset(dp,-1,sizeof(dp));
        
        
//         return f(n,m,s,t);
        
//     }
    
     int minimumDeleteSum(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         
    for(int i=1 ; i<=n ; i++)                 // base case filling up
        dp[i][0] = dp[i-1][0] + s[i-1];

    for(int j=1; j<=m ; j++)                 // base case filling up
        dp[0][j] = dp[0][j-1] + t[j-1];
         
         for(int i=1;i<=n;i++){
             for(int j=1;j<=m;j++){
                 if(s[i-1]==t[j-1]){
                     dp[i][j]= dp[i-1][j-1];
                }else{

                int ds=s[i-1]+dp[i-1][j];
                int dt=t[j-1]+dp[i][j-1];

                 dp[i][j]= min({ds,dt});
                 }
             }
         }
        
        return dp[n][m];
        
    }
    
};