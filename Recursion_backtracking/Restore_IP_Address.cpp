#include<bits/stdc++.h>

void func(string &s,int i,int k,string curr,vector<string>&res){
    
    if(i==s.size() or k<0){
        if(k==0)
        res.push_back(curr.substr(1));
        return;
    }
    for(int j=0;j<3 and i+j<s.size();j++){
        if(stoi(s.substr(i,j+1))>255)break;
        func(s,i+1+j,k-1,curr+"."+s.substr(i,j+1),res);
             if(s[i]=='0')break;
    }
   
    
}
//ques is same as palindrome partitioning
vector<kstring> generateIPAddress(string s)
{
	vector<string>res;
    if(s.size()<=3)return res;
   
   func(s,0,4,"",res);
    return res;
}