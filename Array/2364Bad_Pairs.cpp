class Solution {
public:
    long long countBadPairs(vector<int>& a) {
          unordered_map<int,int> mp;
            int n=size(a);
        long long cnt=0;
            for(int i=0;i<n;i++){
                cnt+= mp[i-a[i]];
                mp[i-a[i]]++;
            }
    return 1L*n*(n-1)/2 - cnt;
    }
};