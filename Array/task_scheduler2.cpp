
//2365 leetcode


class Solution {
public:
    long long taskSchedulerII(vector<int>& task, int space) {
      long long currday=0;
        unordered_map<int,long long>mp;
        for(int i=0;i<task.size();i++){
           
            if(mp.count(task[i])){
             currday=max(currday,mp[task[i]]);   
            }
            mp[task[i]]=currday+space+1;
            currday+=1;
        }
        return currday;
    }
};