#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
#define ll long long
#define ull unsigned long long
#define push_back push_back
#define in insert
#define nl cout << "\n"
#define elif else if
#define mod 1000000007
#define mode 1000000009
#define f(i,a,b) for(ll i = a; i <= b; i++)
#define fr(i,a,b) for(ll i = a; i >= b; i--)
typedef pair<ll, ll> pp;
bool com(pp x, pp y)
{
    if(x.first == y.first) 
        return x.second < y.second;
    return x.first < y.first;
}
ll powerexp(ll x, ll n)
{
    ll result = 1;
    while (n)
    {
        if (n & 1)
            result = result * x % mod;
        n = n / 2;
        x = x * x % mod;
    }
    return result;
}
ll gcd(ll a,ll b)
{
   if(b==0)
       return a;
   return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
//-----------Main function------
 
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
//    ll t;
//    cin >> t;
//    while (t--)
//    {
//        ll n;
//        cin >> n;
      
//    }

ll n;
cin>>n;
vector<vector<ll>>a(n,vector<ll>(n,0));

vector<vector<ll>>v;
for(ll i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    for(ll j=x;j<=y;j++){
        a[i][j]=1;
    }
  
}

ll maxi=0;
vector<ll>curr(n,0),prev(n,0);
for(ll i=0;i<n;i++){
    for(ll j=0;j<n;j++){
        if(a[i][j]==0 or i==0 or j==0){
            curr[j]=a[i][j];
        }else{
            curr[j]=1+min(prev[j],min(prev[j-1],curr[j-1]));
        }
        maxi=max(maxi,curr[j]);
    }
    prev=curr;
}


cout<<maxi<<endl;


   return 0;
}
