class Solution {
public:
    char dfs(unordered_map<char,vector<char>>&adj,char curr,vector<int>&vis){
        char mini=curr;
        vis[curr-'a']=1;
        
        for(auto i:adj[curr])
        {
            if(!vis[i-'a']){
                mini=min(mini,dfs(adj,i,vis));
                
            }
        }
        return mini;
    }
    string smallestEquivalentString(string s1, string s2, string base) {
        unordered_map<char,vector<char>>adj;
        string res="";
        int n=s1.size();
        for(int i=0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
           
        }
        int i=0;
        
        while(i<base.size()){
            auto curr=base[i];
            vector<int>vis(26,0);
            auto a=dfs(adj,curr,vis);
            res+=a;
            i++;
        }
        return res;
    }
};

// a--c
// c--a
// b--d
// d--b
// c--e
// e--c
// a--e
// e--a
