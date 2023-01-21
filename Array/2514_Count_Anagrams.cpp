class Solution {
public:
    long modexp(long a, long b, long mod){
        long ans=1;
        
        while(b>0){
            if((b%2)==1){
                ans=(ans*a)%mod;
            }
            b/=2;
            a=(a*a)%mod;
        }
        
        return ans;
    }
    long count(long c[], long f[], long mod){
        long ans=1, n=0, i;
        
        for(i=0; i<26; i++){
            n=n+c[i];
        }
        //cout<<n<<" ";
        ans=f[n];
        
        for(i=0; i<26; i++){
            // ans=(ans/f[c[i]])%mod;this will give wrong answer
            ans=(ans*modexp(f[c[i]], mod-2, mod))%mod;
        }
        
        for(i=0; i<26; i++){
            c[i]=0;
        }
        
        return ans;
    }
    int countAnagrams(string s) {
        long mod=1000000007, i, j, n, c[26], ans=1;
        long f[100001];
        long k;
        string b="";
        
        f[0]=1;
        
        for(i=1; i<=100000; i++){
            k=(long(f[i-1])*long(i))%mod;
            f[i]=k;
        }
        
        n=s.size();
        
        
        for(i=0; i<26; i++){
            c[i]=0;
        }
        
        for(i=0; i<n; i++)
        {
            if(s[i]==' '){
                ans=(ans*count(c, f, mod))%mod;
            }else if(i==n-1){
                c[s[i]-97]++;
                ans=(ans*count(c, f, mod))%mod;
            }else{
                c[s[i]-97]++;
            }
        }
        
        return int(ans);
        
    }
};