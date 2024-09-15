class Solution {
public:
   
    int findTheLongestSubstring(string s) {
       int res=0;
        int n=s.size();
        map<int,int>mp;
        mp[0]=-1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a' or s[i]=='e' or s[i]=='o' or s[i]=='i' or s[i]=='u'){
                cnt=cnt^(1<<(int)(s[i]-'a'));
            }
            if(mp.find(cnt)!=mp.end()){
                res=max(res,i-mp[cnt]);
            }else{
                mp[cnt]=i;
            }
        }
        return res;
       
        
    }
};

