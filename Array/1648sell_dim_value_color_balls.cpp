
//hard lvl question try to do it again




class Solution {
public:
    int maxProfit(vector<int>& A, int orders) {
       sort(A.begin(),A.end());
        int n=A.size();
        long long res=0;
        int M=1e9+7;
        
        for(int i=n-1;i>=0;i--){
            long long diff=A[i]-(i>0?A[i-1]:0);
            //number of orders which we want in this iteration
            long long x=min((long long)orders,(long long)(n-i)*diff);
            long long r=A[i];
            long long l=r-x/(n-i);
            res+=(r*(r+1)/2 - l*(l+1)/2)*(n-i);
            res%=M;
            res+=l*(x%(n-i));
            res%=M;
            orders-=x;
        }
        return res;
    }
};