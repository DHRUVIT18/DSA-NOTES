class Solution {
public:
    int rev(int n){
        int x=0;
        while(n){
            x=x*10+n%10;
            n/=10;
        }
       
        return x;
    }
    int countNicePairs(vector<int>& nums) {
        int cnt=0;
        int M=1e9+7;
        unordered_map<int,int>mp;
        for(auto num:nums){
            cnt=(cnt+mp[num-rev(num)])%M;
            mp[num-rev(num)]++;
        }
        return cnt;
    }
};