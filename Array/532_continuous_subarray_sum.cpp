// 523. Continuous Subarray Sum

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //check every subarray
        //map
        map<int,int>mp;
        int n=nums.size();
        int pre=0;
        for(int i=0;i<n;i++){
            pre+=nums[i];
            pre%=k;
            if(pre==0 and i>0){
                return true;
            }
            if(mp.find(pre)==mp.end()){
                mp[pre]=i;
            }else{
                if((i-mp[pre])>1){
                    return true;
                }
            }
        }
        return false;
    }
};