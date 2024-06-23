class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int j=0;
        int res=0;
        multiset<int>m;
        for(int i=0;i<n;i++){
           m.insert(nums[i]);
           while(!m.empty() && *m.rbegin()-*m.begin()>limit){
             m.erase(m.find(nums[j]));
               j++;
           }
            res=max(res,i-j+1);
        }
        return res;
    }
};

