/*
    Time Complexity: O(N * log(N))
    Space Complexity: O(N)

    Where 'N' is the number of elements the given arrays.
*/

#include<queue>
#include<set>
#include<algorithm>


//very nice question from codestudio
//link-https://www.codingninjas.com/codestudio/problems/k-max-sum-combinations_975322?topList=striver-sde-sheet-problems&leftPanelTab=0



vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
    sort(begin(a),end(a));
    sort(begin(b),end(b));
    priority_queue<pair<int,pair<int,int>>>q;
    q.push({a[n-1]+b[n-1],{n-1,n-1}});
    set<pair<int,int>>s;
    s.insert({n-1,n-1});
    vector<int>res;
    
    while(k>0)
    {
        auto curr=q.top();q.pop();
        int sum=curr.first;
        int x=curr.second.first;
        int y=curr.second.second;
        
        res.push_back(sum);
        if(s.count({x-1,y})==0){
            q.push({a[x-1]+b[y],{x-1,y}});
            s.insert({x-1,y});
        }
        if(s.count({x,y-1})==0){
            q.push({a[x]+b[y-1],{x,y-1}});
            s.insert({x,y-1});
        }
        
        k--;
    }
    return res;
}




