#define ll long long
class Solution {
public:
    bool valid(ll d1,ll d2,ll c1,ll c2,ll mid){
        ll divByD1=mid/d1,divByD2=mid/d2;
        ll notDivByD1=mid-divByD1,notDivByD2=mid-divByD2;
        
        ll notDivByBoth=mid-mid/lcm(d1,d2);
        
        if(notDivByD1>=c1 and notDivByD2>=c2 and notDivByBoth>=(c1+c2)){
            
            return true;
        }
        return false;
    }
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        ll ans =INT_MAX,l=1,h=INT_MAX;
        
        while(l<=h){
            ll mid=(l+h)>>1;
            if(valid(div1,div2,cnt1,cnt2,mid)){
                ans=min(ans,mid);
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};