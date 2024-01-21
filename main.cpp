#include <bits/stdc++.h>
#include<algorithm>
#include<iomanip>
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
bool check(vector<int>t,vector<int>v){
  for (int i = 1; i < t.size(); i++)
  {
    if(v[t[i]]-v[t[i-1]]!=t[i]-t[i-1])return false;
  }
  return true;
}

bool sortcol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}

void solve(){
 
}



  
 


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

int t;
cin>>t;
while(t--){
solve();

 }
// solve();


return 0;
  
}
  









