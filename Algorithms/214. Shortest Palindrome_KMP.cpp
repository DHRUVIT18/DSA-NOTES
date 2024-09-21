class Solution {
public:
    string shortestPalindrome(string s) {
       
        int count = kmp(string(s.rbegin(),s.rend()),s);
        return string(s.rbegin(),s.rend()).substr(0,s.length()-count)+s;
    } 
    int kmp(const string &text,string &pattern){
        string ns = pattern+"#"+text;
        int i=1,k=0;
        vector<int>pi(ns.length(),0);
        while(i<ns.length()){
            if(ns[i]==ns[k]){
                k++;
                pi[i]=k;
                i++;
            }else{
                if(k>0){
                    k=pi[k-1];
                }else{
                    pi[i]=0;
                    i++;
                }
            }
        }
        return pi.back();
    }
       
};