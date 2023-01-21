class Solution {
public:
    unordered_map<int,vector<int>>adj;
    string s;
    vector<int>res;
   vector<int> dfs(int node,int p){
       vector<int>count(26,0);
       for(auto it:adj[node]){
           if(it!=p){
               auto tmp=dfs(it,node);
               for(int i=0;i<26;i++){
                   count[i]+=tmp[i];
               }
           }
       }
       int c=s[node]-'a';
       count[c]++;
       res[node]=count[c];
       return count;
   }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        res.resize(n,1);
        s=labels;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);              
            
            adj[i[1]].push_back(i[0]);
        }
       dfs(0,-1);

        return res;
    }
};
