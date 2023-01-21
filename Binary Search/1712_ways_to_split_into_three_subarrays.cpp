class Solution {
public:
 
    int waysToSplit(vector<int>& nums) {
       int i,left,remaining,mid_start,mid_end,max_mid,
        length,n=nums.size();
        int mod=1e9+7;
        vector<int>sum(n,0);
        long long ans=0;
        sum[0]=nums[0];
        for(int i=1;i<n;i++)
            sum[i]=sum[i-1]+nums[i];
        
        for(int i=0;i<n;i++){
            left=sum[i];
            remaining=sum[n-1]-left;
            max_mid=remaining/2;
            mid_start=lower_bound(sum.begin()+i+1,sum.end(),sum[i]+left)-sum.begin();
            mid_end=upper_bound(sum.begin()+i+1,sum.begin()+n-1,sum[i]+max_mid)-sum.begin();
            mid_end--;
            length=(mid_end-mid_start+1);
            ans+=max(0,length);
        }
        return ans%mod;
    }
};