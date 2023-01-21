class Solution {
public:
    bool calc(int index,vector<int>&ans,vector<bool>&vis,int n){
        if(index==ans.size())return true;
        if(ans[index]!=0)return calc(index+1,ans,vis,n);
        else{
            for(int i=n;i>=1;i--){
                if(vis[i])continue;
                vis[i]=true;
                ans[index]=i;
                if(i==1){
                    if(calc(index+1,ans,vis,n))return true;
                }else if(index+i<ans.size() and ans[index+i]==0){
                    ans[i+index]=i;
                    if(calc(index+1,ans,vis,n))return true;
                    ans[index+i]=0;
                }
                ans[index]=0;
                vis[i]=false;
            }
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1,0);
        vector<bool>visited(n+1,false);
        calc(0,res,visited,n);
        return res;
    }
};