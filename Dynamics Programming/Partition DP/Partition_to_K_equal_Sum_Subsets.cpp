class Solution {
public:
    bool func(int i,int curr_sum,int k,int target,vector<int>&nums,vector<int>&vis){
        if(k==1)return true;
        if(i==nums.size())return false;
        if(curr_sum==target){
            //we found 1 partition, reset tmp values go back and find other partitions;
            return func(0,0,k-1,target,nums,vis);
        }
        for(int j=i;j<nums.size();j++){
            if(vis[j] or curr_sum+nums[j]>target)continue;
            vis[j]=1;
            if(func(j+1,curr_sum+nums[j],k,target,nums,vis))return true;
            vis[j]=0;
            
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
       int n=nums.size(); 
        int sum=accumulate(begin(nums),end(nums),0);
        sort(rbegin(nums),rend(nums));
        if(sum%k)return false;
        vector<int>vis(n,0);
        return func(0,0,k,sum/k,nums,vis);
        
    }
};