#include<bits/stdc++.h>
using namespace std;

void helper(TreeNode<int>* root){

    if(root==NULL || root->right==NULL && root->left==NULL)return;
    if(root->left!=NULL){
        helper(root->left);
        TreeNode<int>* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        TreeNode<int>* a=root;
        while(root->right!=NULL){
            root=root->right;
        }
        root->right=temp;
    }
    helper(root->right);
}


TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    helper(root);
    return root;
}