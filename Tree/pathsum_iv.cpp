#include<bits/stdc++.h>

unordered_map<int,int>mp;

int dfs(int pos,int presum){
    int d=pos/10;
    
    int p=pos%10;
    
    int left=(d+1)*10+2*p-1;
    int right=(d+1)*10+2*p;
    
    int currsum=presum+mp[pos];
    if(!mp.count(left) and !mp.count(right)){
        return currsum;
    }
    int leftsum=0,rightsum=0;
    while(mp.count(left)){
      leftsum=  dfs(left);
    }
    while(mp.count(right)){
        rightsum=dfs(right);
    }
    return leftsum+rightsum;
}

int pathSum(vector<int> &a, int n)
{
	mp.clear();
    for(auto it:a){
        int x=it%10;
        int y=it/10;
        mp[y]=x;
    }
    return dfs(a[0]/10,0);
}