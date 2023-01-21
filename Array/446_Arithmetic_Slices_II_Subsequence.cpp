
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<map<int,int>>mp(n);
        int res=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                long diff=(long)nums[j]-nums[i];
                if(diff<=INT_MIN or diff>INT_MAX)continue;
                int dif=(int)diff;
                int n2=mp[i][dif];
                int n1=mp[j][dif];
                res+=n1;
                int freq=n1+n2+1;
                mp[i][dif]=freq;
            }
        }
        return res;
    }
};