class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long l=index;
        long r=n-index-1;
        long ans=0;
        long L=1,R=maxSum,M;
        while(L<=R){
            M=(L+R)>>1;
            long sum=M;
            long ls=0;
            long rs=0;
            long m=M-1;
            
            if(r<=m){
                rs=(m*(m+1))/2-((m-r)*(m-r+1))/2;
            }else{
                rs=(m*(m+1))/2+1*(r-m);
            }
            
            if(l<=m){
                ls=(m*(m+1))/2-((m-l)*(m-l+1))/2;
            }else{
                ls=(m*(m+1))/2+1*(l-m);
            }
            
            sum+=ls+rs;
            if(sum<=maxSum){
                ans=M;
                L=M+1;
            }else{
                R=M-1;
            }
            
        }
        return ans;
    }
};