class Solution {
public:
    int f(int i,vector<vector<int>>&books,int shelfWidth,vector<int>&dp){
        if(i==books.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int res=INT_MAX,maxHeight=0,width=0;
        for(int j=i;j<books.size();j++){
           width+=books[j][0];
            if(width>shelfWidth)break;
            maxHeight=max(maxHeight,books[j][1]);
            res=min(res,maxHeight+f(j+1,books,shelfWidth,dp));
        }
       return dp[i]=res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int>dp(n,-1);
       return f(0,books,shelfWidth,dp);
    }
};