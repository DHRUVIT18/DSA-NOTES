//330 leetcode

//make maxreach equal to n

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int i=0;
        int count=0;
        long maxreach=0;
        while(maxreach<n){
            if(i>=nums.size()){
                maxreach+=maxreach+1;
                count++;
            }
            else if(i<nums.size() and nums[i]<=maxreach+1){
                maxreach+=nums[i];
                i++;
            }else{
                maxreach+=maxreach+1;
                count++;
            }
        }
        return count;
    }
};


// [1,2,31,33]
// 2147483647
