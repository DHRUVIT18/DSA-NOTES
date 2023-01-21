#include<bits/stdc++.h>

class Solution {
public:
    //method1 sort array it will give inorder and find bst O(nlogn);
    //method 2 O(n);
    TreeNode* f(vector<int>&A,int &i,int boundary){
        if(i>=A.size() or A[i]>=boundary){
            return NULL;
        }
        
        TreeNode* root=new TreeNode(A[i]);
        
        i++;
        
        root->left=f(A,i,root->val);
        
        root->right=f(A,i,boundary);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return  f(preorder,idx,INT_MAX);
    }
};