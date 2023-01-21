class Solution {
public:
    int f(vector<int>& arr, int target,int value,int sum){
        for(int i=0;i<arr.size();i++){
            if(arr[i]>value){
                int x=arr[i]-value;
                sum-=x;
            }
        }
        return abs(sum-target);
    }
    int findBestValue(vector<int>& arr, int target) {
        int sum=accumulate(begin(arr),end(arr),0);
        int L=0,R=target;
        //at some point diffrence will increase then decrease it work like monotonic function....
        while(L<=R){
            int M=(L+R)>>1;
            if(f(arr,target,M,sum)<=f(arr,target,M+1,sum)){
                
                R=M-1;
            }else{
                L=M+1;
            }
        }
        
        return L;
    }
};