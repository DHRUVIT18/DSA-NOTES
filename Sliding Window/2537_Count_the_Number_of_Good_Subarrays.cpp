class Solution {
public:
    long long count(unordered_map<int,int>&mp){
        long long res=0;
        for(auto it:mp){
            int f=it.second;
            res+=(f*(f-1))/2;
        }
        return res;
    }
    long long countGood(vector<int>& nums, int k) {
        long long res=0;
        unordered_map<int,int>mp;
        int i=0;
        int n=nums.size();
        int freq=0;
        for(int j=0;j<nums.size();j++){
            mp[nums[j]]++;
            freq+=mp[nums[j]]-1;
            while(i<j and freq>=k){
                res+=n-j;
                
                mp[nums[i]]--;
                freq-=mp[nums[i]];
                i++;
            }
            
        }
        return res;
    }
};