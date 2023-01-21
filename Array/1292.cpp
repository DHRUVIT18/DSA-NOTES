
// 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold


class Solution {
public:
    bool valid(vector<vector<int>>&presum,int len,int threshold){
       int sum=INT_MAX;
        for(int i=0;i<presum.size();i++){
            for(int j=0;j<presum[0].size();j++){
                if(i-len>=0 and j-len>=0){
                    sum=min(sum,presum[i][j]-presum[i-len][j]-presum[i][j-len]+presum[i-len][j-len]);
                }
            }
        }
        return sum<=threshold;
    }
    int maxSideLength(vector<vector<int>>& A, int threshold) {
        int n=A.size(),m=A[0].size();
        vector<vector<int>>presum(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                presum[i][j]=A[i-1][j-1]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
            }
        }
        
        // for(auto it:presum){
        //     for(auto i:it){
        //         cout<<i<<" ";
        //     }
        //     cout<<endl;
        // }
        int L=0,R=min(n,m);
        while(L<=R){
            int M=(L+R)>>1;
            if(valid(presum,M,threshold)){
                L=M+1;
            }else{
                R=M-1;
            }
        }
        
        return R;
    }
};