class Solution {
public:
    int maximizeWin(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        int start=0;
        int res=0;
        vector<int>dp(n);
        for(int end=0;end<n;end++){
            
            while(nums[end]-nums[start]>k){
                start++;
            }
            int curr_ans=end-start+1;
            if(start>0)curr_ans+=dp[start-1];
            
            res=max(res,curr_ans);
            
            int p=0;
            if(end>0)p=dp[end-1];
            
            dp[end]=max(p,end-start+1);
            
        }
       return res;
    }
};