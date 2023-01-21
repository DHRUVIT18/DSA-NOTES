class Solution {
public:
   long long f(vector<int>&nums,vector<int>&cost,int median){
       long long res=0;
       for(int i=0;i<nums.size();i++){
           res=res+abs(nums[i]-median)*(1ll*cost[i]);
       }
       return res;
       
   }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long total=0,sum=0;
        long long n=nums.size();
      
        vector<vector<int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++){
            sum=sum+1ll*v[i][1];
        }
        long long median;
        int i=0;
        
        while(total<(sum+1)/2 and i<n){
            total=(total+1ll*v[i][1]);
            median=v[i][0];
            i++;
            
        }
        
      return f(nums,cost,median);
    }
};