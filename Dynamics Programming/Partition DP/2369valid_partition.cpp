class Solution {
public:
    int f(int i,vector<int>&nums,vector<int>&dp){
        
        if(i==nums.size()){
            return true;
        }
        if(i>nums.size())return false;
        if(dp[i]!=-1)return dp[i];
        
        int equal2=0,equal3=0,consecutive3=0;
        if(i+1<nums.size() and nums[i]==nums[i+1]){
            if(f(i+2,nums,dp))return true;
            if(i+2<nums.size() and nums[i]==nums[i+2]){
                if(f(i+3,nums,dp))return true;
            }
        }
        
        if(i+2<nums.size() and nums[i]==nums[i+1]-1 and nums[i]==nums[i+2]-2){
            if(f(i+3,nums,dp))return true;
        }
        
        
        
        return dp[i]= false;
    }
    
    bool validPartition(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};