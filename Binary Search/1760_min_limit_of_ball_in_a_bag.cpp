class Solution {
public:
    bool ispossible(vector<int>&nums,int maxOperations,int mid){
        int reqops=0;
        for(auto it:nums){
            int x=it/mid;
            
            if(it%mid==0){
                x--;
            }
            reqops+=x;
        }
        return reqops<=maxOperations;
    }
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int start=1,end=*max_element(nums.begin(),nums.end());
       int ans=end;
        while(start<=end){
            int mid=(start+end)>>1;
            if(ispossible(nums,maxOperations,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};