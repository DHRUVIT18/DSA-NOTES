

#include<bits/stdc++.h>
bool isleaf(TreeNode<int>*root){
    if(!root->left and !root->right)return true;
    return false;
}
void right(TreeNode<int>*root,vector<int>&res){
    TreeNode<int>*curr=root->right;
    vector<int>tmp;
    while(curr){
        if(!isleaf(curr))tmp.push_back(curr->data);
        if(curr->right)curr=curr->right;
        else curr=curr->left;
    }
    for(int i=tmp.size()-1;i>=0;i--){
        res.push_back(tmp[i]);
    }
}

void left(TreeNode<int>*root,vector<int>&res){
    TreeNode<int>*curr=root->left;
    while(curr){
        if(!isleaf(curr))res.push_back(curr->data);
        if(curr->left)curr=curr->left;
        else curr=curr->right;
    }
}

void inorder(TreeNode<int>*root,vector<int>&res){
    if(!root)return ;
    inorder(root->left,res);
    if(!root->left and !root->right){
        res.push_back(root->data);
    }
    inorder(root->right,res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int>res;
    if(!root)return res;
    if(!isleaf(root))res.push_back(root->data);
    left(root,res);
    inorder(root,res);
    right(root,res);
    return res;
}
