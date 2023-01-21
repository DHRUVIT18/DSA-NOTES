class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
       vector<int>res;
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        long long time=tasks[0][0];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int i=0;
        while(!q.empty() or i<tasks.size()){
            while(i<tasks.size() and time>=tasks[i][0]){
                q.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(!q.empty()){
                auto curr=q.top();
                q.pop();
                res.push_back(curr.second);
                time+=curr.first;
            }else{
                time=tasks[i][0];
            }
        }
        return res;
    }
};

