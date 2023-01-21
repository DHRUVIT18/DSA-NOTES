
//next lvl question
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n=nums.size();
        long long res=0,prev=nums[n-1];
       
        for(int i=n-2;i>=0;i--){
            int x=nums[i]/prev;
            if(nums[i]%prev!=0)x++;
            if(nums[i]%prev!=0){
                prev=nums[i]/x;
            }
            res+=x-1;
        }
        return res;
    }
};
