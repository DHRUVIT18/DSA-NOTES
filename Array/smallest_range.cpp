//910 leetcode

//smallest range 
//Sort the vector.
// Assuming there is a point, on the left of the point, all elements add K, on the right of the point, all elements substract K, check each possible point. (a point is between two numbers).


class Solution {
public:
 
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int res=nums[n-1]-nums[0];
        int left=nums[0]+k,right=nums[n-1]-k;
        for(int i=0;i<n-1;i++){
            int maxi=max(nums[i]+k,right);
            int mini =min(nums[i+1]-k,left);
            res=min(res,maxi-mini);
        }
      return res;
    }
};