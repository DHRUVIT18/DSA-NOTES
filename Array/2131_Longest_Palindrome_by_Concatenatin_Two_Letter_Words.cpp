class Solution {
public:
   
    int longestPalindrome(vector<string>& words) {
       int res=0;
        map<string,int>mp;
        for(auto it:words){
            mp[it]++;
        }
        bool f=false;
        for(auto i:words){
            string j=i;
            reverse(j.begin(),j.end());
            if(j!=i and mp[j]>0 and mp[i]>0){
                mp[j]--;
                mp[i]--;
                res+=4;
            }else if(j==i and mp[i]>1){
                res+=4;
                mp[i]-=2;
            }else if(j==i and !f and mp[i]>0){
                res+=2;
                mp[i]--;
                f=true;
            }
        }
        return res;
    }
};