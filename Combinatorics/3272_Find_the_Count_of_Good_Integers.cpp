#define ll long long
#define ld long double
ll ans;

vector<ll>fact;

unordered_map<string,int>vis;

string generatePalindrome(ll num ,ll val){
    string s=to_string(num);
    string t=s.substr(0,val);
    reverse(t.begin(),t.end());
    
    s+=t;
    return s;
}

bool check(string &s,int k){
    ll val=0;
    for(int i=0;i<s.size();i++){
        ll curr=s[i]-'0';
        val = val*10+curr;
    }
    return val%k==0;
}

ll count(string &s){
    vector<ll>fr(10,0);
    ll n=s.size();
    
    if(n==1)return 1;
    
    for(int i=0;i<n;i++){
        ll curr=s[i]-'0';
        fr[curr]++;
    }
    
    ll tot=fact[n];
    string str="";
    
    for(int i=0;i<10;i++){
        ll curr=fr[i];
        str+=('a'+curr);
        
        if(curr!=0){
            tot=tot/fact[curr];
        }
    }
    
    if(vis.find(str)!=vis.end()){
        return 0;
    }
    vis[str]=1;
    
    if(fr[0]==0)return tot;
    
    ll a=fact[n-1];
    a=a/fact[fr[0]-1];
    
    for(int i=1;i<10;i++){
         ll curr = fr[i];
        
        if(curr != 0)
            a = a/fact[curr];
    }
    ll res=tot-a;
    
    return res;
}


void find(int pos,int num,int len,int stat,int k){
    if(pos==len){
        ll val;
        if(stat==1){
            val=len-1;
        }else{
            val=len;
        }
        string s=generatePalindrome(num,val);
        bool st=check(s,k); // check divisibility by k
        
        if(st){// if yes count all possible combinations
            ans+=count(s);
        }
        return;
    }
    
    if(pos==0){
        for(int i=1;i<=9;i++){
            int tnum=num*10+i;
            find(pos+1,tnum,len,stat,k);
        }
    }else{
        for(int i=0;i<=9;i++){
            int tnum=num*10+i;
            find(pos+1,tnum,len,stat,k);
        }
    }
    return;
}

class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        ll len;
        ans=0;
        int stat;
        
        fact.clear();
        vis.clear();
        
        fact.push_back(1);
        ll curr=1;
        
        for(ll i=2;i<=11;i++){
            fact.push_back(curr);
            curr=curr*i;
        }
        
        if(n%2==1){
            stat=1;
        }else{
            stat=0;
        }
        len = (n+1)/2;
        
        find(0,0,len,stat,k);
        
        return ans;
    }
};