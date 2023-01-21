class Solution {
public:
   
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++){
            v[i]={nums2[i],nums1[i]};
        }
        
        sort(v.rbegin(),v.rend());
        
        long long sum=0,res=0;
        
        
        priority_queue<int,vector<int>,greater<int>>q;
        
        for(auto [i,j]:v){
            
            q.push(j);
            
            sum+=j;
            
            if(q.size()>k){
                sum-=q.top();
                q.pop();
                
            }
            if(q.size()==k){
                res=max(res,sum*i);
            }
        }
        
        return res;
    }
};