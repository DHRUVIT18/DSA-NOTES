
//classic sliding window problem


class Solution {
public:
    bool valid(vector<int>&s,vector<int>&t){
        for(int i=0;i<s.size();i++){
            if(t[i]>0){
                if(s[i]<t[i])return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        
        string res="";
        if(t.size()>s.size())return "";
        if(s==t)return s;
        vector<int>mpt(150,0),mps(150,0);
        for(auto it:t){
            mpt[it]++;
        }
        int i=0,j=0;
        for(;j<s.size();j++){
            mps[s[j]]++;
            while(valid(mps,mpt)){
               
                 if(res.size()==0 or (j-i+1)<=res.size()){
                string tmp="";
                for(int k=i;k<=j;k++){
                    tmp+=s[k];
                }
                res=tmp;
            }
                 mps[s[i]]--;
                i++;
            }
           
        }
      
        return res;
    }
};