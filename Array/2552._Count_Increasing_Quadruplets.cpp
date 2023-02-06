class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        int n=nums.size();

        vector<vector<int>>greaterthan(n,vector<int>(n,0)),lessthan(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=i+1,greater=0;j<n;j++){
                greater+=(nums[j]>nums[i]);
                greaterthan[i][j]=greater;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i-1,lesser=0;j>=0;j--){
                lesser+=(nums[j]<nums[i]);
                lessthan[j][i]=lesser;
            }
        }
        long long res=0;
        for(int j=1;j<n-2;j++){
            for(int k=j+1;k<n-1;k++){
                if(nums[k]<nums[j]){
                    int poss_i=(lessthan[0][k]-lessthan[j][k]);
                    int poss_l=(greaterthan[j][n-1]-greaterthan[j][k]);
                    res+=1ll*poss_i*poss_l;
                }
            }
        }
        return res;
    }
};