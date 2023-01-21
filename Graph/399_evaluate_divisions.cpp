
//created graph with equations and values 

// a->{b,2.0};
// a->{b,1/2.0};
//created visited map 
//great question on graph



class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>mp;
    unordered_map<string,bool>vis;
    double queryans;
    bool dfs(string src,string dest,double total){
        if(src==dest and mp.find(src)!=mp.end()){
            queryans=total;
            return true;
        }
        bool tempans=false;
        vis[src]=true;
        for(int i=0;i<mp[src].size();i++){
            if(!vis[mp[src][i].first]){
                tempans=dfs(mp[src][i].first,dest,total*mp[src][i].second);
                if(tempans)
                    break;
            }
        }
        vis[src]=false;
        return tempans;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int m=queries.size();
        for(int i=0;i<equations.size();i++){
            mp[equations[i][0]].push_back({equations[i][1],values[i]});
            mp[equations[i][1]].push_back({equations[i][0],(double)1/values[i]});
            vis[equations[i][0]]=false;
            vis[equations[i][1]]=false;
        }
        vector<double>ans(m);
        for(int i=0;i<m;i++){
            queryans=1;
            bool pathfound=dfs(queries[i][0],queries[i][1],1);
            if(pathfound)ans[i]=queryans;
            else ans[i]=-1;
        }
      
        return ans;
    }
};