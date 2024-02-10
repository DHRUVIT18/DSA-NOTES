class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
    vector<int>dp(n,1),hash(n);
    int maxi=1;
    int last=0;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        hash[i]=i;
        for(int prev=0;prev<i;prev++){
            if(arr[i]%arr[prev]==0 and 1+dp[prev]>dp[i] ){
                
                dp[i]=1+dp[prev];
                hash[i]=prev;
            }
        }
        if(dp[i]>maxi){
        maxi=dp[i]; 
            last=i;
        }   
    }
    vector<int>tmp;
    tmp.push_back(arr[last]);
    while(hash[last]!=last){
        last=hash[last];
        tmp.push_back(arr[last]);
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
    }
};