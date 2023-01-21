class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        stack<int>s1,s2;
        int n=a.size();
        vector<int>next_smaller(n),prev_smaller(n);
        for(int i=0;i<n;i++){
            next_smaller[i]=n-i-1;
            prev_smaller[i]=i;
        }
        for(int i=0;i<n;i++){
            while(!s1.empty() and a[s1.top()]>a[i]){
                next_smaller[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() and a[s2.top()]>=a[i]){
                prev_smaller[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
         long res=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++){
            res=(res+(long)a[i]*(next_smaller[i]+1)*(prev_smaller[i]+1))%mod;
        }
        
        return res;
    }
};