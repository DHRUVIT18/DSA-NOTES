
#include<bits/stdc++.h>
int cnt=0;
int func(TreeNode<int>*root,long long int &res){
    if(!root)return 0;
    if(root -> left == NULL && root -> right == NULL) cnt++;
    int l=func(root->left,res);
    int r=func(root->right,res);
    int tmp=max(max(l,r)+root->val,root->val);
    int ans=max(tmp,l+r+root->val);
    //res=max(res,ans);
    if(res<=ans){
        res=ans;
    }
    return tmp;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int res=INT_MIN;
    cnt=0;
    func(root,res);
    
    if(cnt==1)return -1;
    return res==INT_MIN?-1:res;
}







