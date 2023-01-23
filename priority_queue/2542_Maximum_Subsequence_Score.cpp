class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        
        vector<vector<int>>v(n);
        
        for(int i=0;i<n;i++){
            v[i]={nums2[i],nums1[i]};
        }
        sort(v.rbegin(),v.rend());
        
        priority_queue<int,vector<int>,greater<int>>q;
        long long res=0,sum=0;
        
        for(int i=0;i<n;i++){
            
            q.push(v[i][1]);
            
            sum+=v[i][1];
            
            if(q.size()>k){
                sum-=q.top();
                q.pop();
            }
            
            if(q.size()==k){
                res=max(res,sum*v[i][0]);
            }
        }
        return res;
    }
};