// 1239. Maximum Length of a Concatenated String with Unique Characters

class Solution {
public:
    bool compare(vector<int>&dp,string s){
        for(auto i:s){
            int t=i-'a';
            if(dp[t]==1)return false;
        }
        vector<int>self(26,0);
        //for "aa","bb" case
        for(auto i:s){
            self[i-'a']++;
        }
        for(auto i:self){
            if(i>1)return false;
        }
        return true;
    }
    int f(int i,vector<string>&a,vector<int>&dp,int len){
        if(i>=a.size()){
            return len;
        }
        string curr=a[i];
        if(compare(dp,curr)==false){
            return f(i+1,a,dp,len);
        }else{
            //pick
            for(int k=0;k<curr.size();k++){
                dp[curr[k]-'a']=1;
            }
            int pick=f(i+1,a,dp,len+curr.size());
            
            for(int k=0;k<curr.size();k++){
                dp[curr[k]-'a']=0;
            }
            
            int notpick=f(i+1,a,dp,len);
            return max(pick,notpick);
        }
    }
    int maxLength(vector<string>& arr) {
        vector<int>dp(26,0);
        return f(0,arr,dp,0);
    }
};