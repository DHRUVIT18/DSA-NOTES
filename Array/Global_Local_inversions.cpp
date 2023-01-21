class Solution {
public:
     // all local inversions are global inversions
    // but the all global is not necessary a local inversion
    //if we can find atleast one extra global inversion we can directly return false
    bool isIdealPermutation(vector<int>& nums) {
        if(nums.size()==1)return true;
        int maxleft=0;
        for(int i=0;i<nums.size()-2;i++){
            maxleft=max(maxleft,nums[i]);
            if(maxleft>nums[i+2]){
                return false;
            }
        }
        return true;
        
    }
};