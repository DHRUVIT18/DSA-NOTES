//2099 
//very good problem 
//insert first k  elements and 
//then iterate over next elements find min remove and insert larger element


class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        int i=0;
        while(k>0){
            ans.push_back(nums[i]);
            i++;
            k--;
        }
        for(int j=i;j<n;j++){
            //return iterator
            int m=min_element(begin(ans),end(ans))-begin(ans);
            if(ans[m]<nums[j]){
                ans.erase(ans.begin()+m);
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};