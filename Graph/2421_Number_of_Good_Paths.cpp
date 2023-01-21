class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    
    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);
        
        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;

        }else{
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
    
        
        
        
        
        
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        //initializing dsu
        int n=vals.size();
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        
        //adj list
        unordered_map<int,vector<int>>adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);

        }
        
        //val-{node}
       map<int,vector<int>>val_to_nodes;
        for(int i=0;i<n;i++){
            val_to_nodes[vals[i]].push_back(i);
        }
        
        int res=n;
        
        vector<bool>is_active(n,false);
        for(auto it:val_to_nodes){
            vector<int>nodes=it.second;
            for(auto u:nodes){
                
                for(auto v:adj[u]){
                    
                    if(is_active[v]){
                        Union(u,v);
                    }
                }
                is_active[u]=true;
            }
            vector<int>your_parents;
            
            for(auto u:nodes){
                int p=find(u);
                your_parents.push_back(p);
            }
            sort(begin(your_parents),end(your_parents));
            int sz=your_parents.size();
            for(int j=0;j<sz;j++){
                long long count=0;
                int curr_parent=your_parents[j];
                while(j<sz and your_parents[j]==curr_parent){
                    j++;
                    count++;
                }
                j--;
                int formula=count*(count-1)/2;
                res+=formula;
            }
        }
        return  res;
    }
};
















