class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& a) {
        long M=1e9+7;
        long res=0;
        sort(a.begin(),a.end());
        unordered_map<int,long>dp;        
        for(int i=0;i<a.size();i++){
          dp[a[i]]=1;
            for(int j=0;j<i;j++){
                if(a[i]%a[j]==0){
                    dp[a[i]]=(dp[a[i]]+(dp[a[j]]*dp[a[i]/a[j]]))%M;
                }
            }
            res=(res+dp[a[i]])%M;
        }
        return res;
    }
};

      
      
       
