
//1574  leetcode

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        
        //calculating for left
        while(low+1<n and arr[low+1]>=arr[low])low++;
        
        if(low==n-1)return 0;
        
        //calculating for right
        while(high>low and arr[high]>=arr[high-1])high--;
        
        int ans=min(n-low-1,high);
        int i=0,j=high;
        
        //calculating for mid part
        while(i<=low and j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }else{
                j++;
            }
        }
        return ans;
    }
};