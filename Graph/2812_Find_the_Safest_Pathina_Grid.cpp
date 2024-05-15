class Solution {
public:

    void buildDis(queue<pair<int,int>>& q, int n, vector<vector<int>>& dis, vector<vector<bool>>& vis){
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int lvl = 0;

        while (!q.empty()) {
            int siz = q.size();
            while(siz--){
                auto [x,y] = q.front();
                q.pop();
                dis[x][y] = lvl;
                for (int i=0; i<4; i++) {
                    int nx = x+dir[i].first, ny = y+dir[i].second;
                    if (nx>=0 && nx<n && ny>=0 && ny<n && !vis[nx][ny]) {
                        q.push({nx,ny});
                        vis[nx][ny] = true;
                    }
                }
            }
            lvl++;
        }
    }

    int findSf(vector<vector<int>>& dis, int n){
        priority_queue<pair<int,pair<int,int>>> pq;
        vector<vector<bool>> vis (n,vector<bool>(n));
        pq.push({dis[0][0],{0,0}});
        vis[0][0] = true;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 1e9;
        while(!pq.empty()){
            auto [d,cord] = pq.top();
            pq.pop();
            int x = cord.first, y = cord.second;
            ans = min(ans,dis[x][y]);
            if(x==n-1 && y==n-1) return ans;
            for(int i=0; i<4; i++){
                int nx = x+dir[i].first, ny = y+dir[i].second;
                if(nx>=0 && nx<n && ny>=0 && ny<n &&!vis[nx][ny]){
                    vis[nx][ny] = true;
                    pq.push({dis[nx][ny],{nx,ny}});
                }
            }
        }
        return ans;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int, int>> q;
        vector<vector<bool>> vis (n,vector<bool>(n));

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    vis[r][c] = true;
                    q.push({r, c});
                }
            }
        }
        
        vector<vector<int>> dis (n,vector<int>(n));

        buildDis(q,n,dis,vis);
        int ans = findSf(dis,n);

        return ans;
    }
};