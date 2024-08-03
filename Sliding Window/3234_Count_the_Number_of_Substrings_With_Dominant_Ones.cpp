class Solution {
public:
    int numberOfSubstrings(string s) {
       int n=s.size();
       int res=0;
       vector<int>prefix(n,0);
        prefix[0]=(s[0]=='0'?0:1);
        for(int i=1;i<n;i++){
            prefix[i]=(s[i]=='0'?0:1)+prefix[i-1];
        }
        for(int i=0;i<n;i++){
            int zeros=0,ones=0;
            for(int j=i;j<n;j++){
                ones=prefix[j];
                if(i!=0)ones-=prefix[i-1];
                zeros=j-i+1-ones;
                
                if(zeros*zeros>ones)j+=((zeros*zeros)-ones-1);
                
                if(zeros*zeros<=ones){
                    res++;
                    if(zeros*zeros<ones){
                        int diff=sqrt(ones)-zeros;
                        int nextj=j+diff;
                        if(nextj>=n){
                            res+=(n-j-1);
                        }else{
                            res+=diff;
                        }
                        j=nextj;
                    }
                }
            }
        }
        return res;
    }
};