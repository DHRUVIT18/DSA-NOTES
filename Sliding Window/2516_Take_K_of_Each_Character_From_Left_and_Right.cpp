class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0)return 0;
        int n=s.size();
        int c[3]={0};
        int i=0,j=0;
        int res=INT_MAX;
        while(j<2*n){
            c[s[j%n]-'a']++;
            while(i<n and c[0]>=k and c[1]>=k and c[2]>=k){
                if(j<n-1){
                    res=min(res,j+1);
                }else{
                    res=min(res,j-i+1);
                }
                c[s[i]-'a']--;
                i++;
            }
            if(j>=n-1 and res==INT_MAX)return -1;
            j++;
        }
        return res;
    }
};