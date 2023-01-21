//162 leetcode



class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n=nums.size();
        int l=0,h=n-1;
        while(l<h){
            int mid=(l+h)/2;
           if(nums[mid]<nums[mid+1]){
             //then atleast one peak element lies on right half
               l=mid+1;
           }else{
               h=mid;
           }
        }
        return h;
    }
};