class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> adj[n + 1];
        for(int i = 1; i <= n - 1; i++) {
            adj[i].push_back(i + 1);
            adj[i + 1].push_back(i);
        }
        if(x != y) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<vector<int>> store;
        for(int h = 1; h <= n; h++) {
            vector<int> dist(n + 1, 1e9);
            dist[h] = 0;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, h});
            while(!pq.empty()) {
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();

                for(auto v : adj[u]) {
                    if(1 + d < dist[v]) {
                        dist[v] = 1 + d;
                        pq.push({1 + d, v});
                    }
                }
            }
            
            store.push_back(dist);
        }
        
        vector<int> ans;
        for(int k = 1; k <= n; k++) {
            int c = 0;
            for(auto v : store) {
                for(auto x : v) {
                    if(x == k) c++;
                }
            }
            ans.push_back(c);
        }
        
        return ans;
    }
};
