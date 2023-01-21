class Solution {
public:
    int func(int ind,int b,int a,vector<int>&nums){
        int ans=0;
        if(ind<0){
            return 0;
        }
        if(a==(b|nums[ind])){
            ans=1;
        }
        return ans+func(ind-1,b,a,nums)+func(ind-1,b|nums[ind],a,nums);
    }
   
    int countMaxOrSubsets(vector<int>& nums) {
       int a=0;
        for(auto i:nums){
            a=a|i;
        }
        int ans=0;
        
       ans+= func(nums.size()-1,0,a,nums);
        return ans;
    }
};