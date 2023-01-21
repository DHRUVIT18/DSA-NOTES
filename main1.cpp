#include <bits/stdc++.h>
#include<algorithm>
#define int long long int
#define endl "\n"
using namespace std;
#define mod 1000000007
#define mode 1000000009

int powerexp(int x, int n)
{
    int result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x % mod;
        n = n / 2;
        x = x * x % mod;
    }
    return result;
}


//if in any ques there is like form this from this and search then only method is hashmap

bool isprime(int n){
    // loop to check if n is prime
     bool is_prime = true;
  for (int i = 2; i <= n/2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }
  return is_prime;
}

int gcd(int a,int b)
{
   if(b==0)
       return a;
   return gcd(b,a%b);
}

bool ispalindrome(string s){
  int l=0,r=s.size()-1;
  while(l<=r){
    if(s[l]!=s[r])return false;
    l++;
    r--;
  }
  return true;

}

int rec(int i,vector<int>&a,int n){
  if(n==0)return 0;
  if(i==a.size()){
    return 0;
  }
  
  int take=INT_MIN;
  if((i)<=n and a[i]!=0){
    take=a[i]+rec(i,a,n-(i));
  }
  int nottake=rec(i+1,a,n);
  return max(take,nottake);
}



void solve(){
  string s;
  cin>>s;
  string res="";
  if(s.find("_")!=string::npos){
    // convert c++ to java
    for(int i=0;i<s.size()-1;i++){
      if(s[i]=='_'){
        s[i+1]=toupper(s[i+1]);
       
      }else{
        res+=s[i];
      }
    }
   res+=s.back();
  }else{
    for(int i=0;i<s.size();i++){
      if(isupper(s[i])){
        res+="_";
        res+=tolower(s[i]);
      }else{
        res+=s[i];
      }
    }
  }
  cout<<res<<endl;
}
 


int32_t main()
{
   solve();

return 0;
  
}
  









