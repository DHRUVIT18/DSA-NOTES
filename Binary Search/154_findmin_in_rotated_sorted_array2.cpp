class Solution {
public:
    int findMin(vector<int>& nums) {
        // int x=nums[0];
        // for(int i=1;i<nums.size();i++){
        //     x=min(x,nums[i]);
        // }
        // return x;
        int L=0,R=nums.size()-1;
        
        while(L<R){
            int M=(L+R)>>1;
           
            if(nums[M]>nums[R]){
                //right half is sorted
                L=M+1;
            }else if(nums[M]<nums[R]){
                //left half is sorted
                R=M;
            }else{
                //for duplicates
                R--;
            }
            
        }
        return nums[R];
    }
};