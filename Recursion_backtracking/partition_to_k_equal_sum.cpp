//698


class Solution {
public:
    bool func(int i,vector<int>&nums,vector<int>&vis,int target,int curr_sum,int k){

        if(k==1)return true;

         if(i>=nums.size())return false;

        if(curr_sum==target){
            //we found 1 subset find another
            return func(0,nums,vis,target,0,k-1);
        }

        //start from every index
        for(int j=i;j<nums.size();j++){
            if(vis[j] or curr_sum+nums[j]>target)continue;
            vis[j]=1;
            if(func(j+1,nums,vis,target,curr_sum+nums[j],k))
                return true;
            vis[j]=0;
        }
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=accumulate(begin(nums),end(nums),0);
         // sort(rbegin(nums),rend(nums));
        if(n<k or sum%k)return  false;
        int target=sum/k;
        vector<int>vis(n,0);
        return func(0,nums,vis,target,0,k);
    }
};