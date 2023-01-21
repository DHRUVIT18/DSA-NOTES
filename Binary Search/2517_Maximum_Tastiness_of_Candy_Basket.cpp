class Solution {
public:
    
    int maximumTastiness(vector<int>& price, int k) {
        
        int low = 0;
        sort(price.begin(),price.end());
        int n = price.size();
        
        int high = price.back()-price[0];
        int res = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int prev = 0;
            int count =1;
            for(int i=0;i<n;i++){
                if(price[i]-price[prev]>=mid){
                    count++;
                    prev = i;
                }
            }
            if(count<k){
                high = mid-1;
            }
            else{
                res = max(res,mid);
                low = mid+1;
            }
        }
        return res;
    }
};