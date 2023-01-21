#include<bits/stdc++.h>



//at first we build lps array of pattern -
//lps array stores prefix suffix longest match

//then we linearly search through in string untill it reaches end



vector<int>lps(string p,int n){
    vector<int>lp(n);
    int len=0;
    int i=1;
    lp[0]=0;
    while(i<n){
        if(p[i]==p[len]){
            len++;
            lp[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lp[len-1];
            }else{
                lp[i]=0;
                i++;
            }
        }
    }
    return lp;
}
bool findPattern(string p, string s)
{
    int m=p.size();
    int n=s.size();
    vector<int>pi=lps(p,m);
    int i=0;
    int j=0;
    while(i<n){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        if(j>=m)return true;
        //mismatch
        
        else if(i<n and s[i]!=p[j]){
            if(j!=0){
                j=pi[j-1];
            }else{
                //j is already 0 then increment i and compare next 
                i=i+1;
            }
        }
    }
       return false;

}