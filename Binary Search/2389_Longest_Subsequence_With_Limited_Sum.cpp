class Solution {
public:
   int f(vector<int>&nums,int k){
       int low=0,high=nums.size()-1;
       while(low<=high){
           int mid=(low+high)>>1;
           if(nums[mid]<=k){
               low=mid+1;
           }else{
               high=mid-1;
           }
       }
       return low;
   }
    
    
   
    vector<int> answerQueries(vector<int>& nums, vector<int>& q) {
        vector<int>res;
        sort(nums.begin(),nums.end());
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<q.size();i++){
            res.push_back(f(prefix,q[i]));
        }
        return res;
    }
};

// [1,2,4,5]
// [1,3,7,12]