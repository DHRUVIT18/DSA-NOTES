class Solution {
public:
   static bool cmp(vector<int>&a1,vector<int>&a2){
       if(a1[0]==a2[0]){
           return (a1[1]-a1[0])>(a2[1]-a2[0]);
       }
       return a1[0]<a2[0];
   }
    int removeCoveredIntervals(vector<vector<int>>& A) 
       {
        sort(A.begin(),A.end(),cmp);
        //we have to find whole overlaping interval;
        //....[2.....[3-----------6].....8]....//
           int start=A[0][0],end=A[0][1];
           int cnt=0;
           for(int i=1;i<A.size();i++){
               if(start<=A[i][0] and A[i][1]<=end){
                   cnt++;
               }else{
                   start=A[i][0];
                   end=A[i][1];
               }
           }
           return A.size()-cnt;
    }
};