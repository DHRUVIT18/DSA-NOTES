class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res=0,i,j,end,start,n;
        n=costs.size();
        priority_queue<int,vector<int>,greater<int>>s,e;
        for(int i=0;i<candidates;i++){
            s.push(costs[i]);
        }
        for(int i=n-1;i>=candidates and i>=n-candidates;i--){
            e.push(costs[i]);
        }
        start=candidates;
        end=n-candidates-1;
        while(k>0){
            if(!s.empty() and !e.empty()){
                if(s.top()<=e.top()){
                    res+=s.top();s.pop();
                    if(start<=end){
                        s.push(costs[start]);
                        start++;
                    }
                }else{
                    res+=e.top();e.pop();
                    if(start<=end){
                        e.push(costs[end]);
                        end--;
                    }
                }
            }else if(s.empty()==false){
                res+=s.top();
                s.pop();
            }else if(e.empty()==false){
                res+=e.top();
                e.pop();
            } 
            k--;
        }
        return res;
    }
};