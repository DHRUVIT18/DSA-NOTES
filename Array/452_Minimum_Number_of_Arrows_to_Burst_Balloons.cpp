class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        //overlap problem - the idea is to maintain lowest interval as possible
        sort(a.begin(),a.end());
        vector<vector<int>>v,res;
        v.push_back(a[0]);
        for(int i=1;i<a.size();i++){
            if(a[i][0]<=v[0][1]){
                //intersection
                //[1,6] , [4,8]
                // 1-----4-----6-----8
                //v[0] become [4,6] 
                v[0][0]=max(v[0][0],a[i][0]);
                v[0][1]=min(v[0][1],a[i][1]);

            }else{
                res.push_back(v[0]);
                v.pop_back();
                v.push_back(a[i]);
            }
        }
        res.push_back(v[0]);
        return res.size();
    }
};

