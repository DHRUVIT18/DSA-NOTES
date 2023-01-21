// Construct Binary Tree From Inorder and Preorder Traversal
#include<bits/stdc++.h>



TreeNode<int>*buildtree(vector<int> &inorder, vector<int> &preorder,unordered_map<int,int>&mp,int left,int right,int &idx){


    if(left>=right)return NULL;
    int mid=mp[preorder[idx]];
    auto root=new TreeNode<int>(preorder[idx]);
    idx++;
    root->left=buildtree(inorder,preorder,mp,left,mid,idx);
    root->right=buildtree(inorder,preorder,mp,mid+1,right,idx);
    return root;

    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	unordered_map<int,int>mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    int idx=0;
    return buildtree(inorder,preorder,mp,0,preorder.size(),idx);
}

