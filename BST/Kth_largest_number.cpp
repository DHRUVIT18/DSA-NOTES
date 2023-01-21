/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>

//or we can first go to right right right and then decrement value of k as well return back if k==0 then node is found
int ans=0;
void f(TreeNode<int>*root,int k)
{
    if(!root)return;
    f(root->right,k);
    k--;
    if(k==0){
        ans=root->data;
        return;
    }
    f(root->left,k);
}


int KthLargestNumber(TreeNode<int>* root, int k) 
{
    //using stack
    //reverse inorder
    //iterative method;
    stack<TreeNode<int>*>st;
    while(root or !st.empty()){
        while(root){
            st.push(root);
            root=root->right;
        }
        root=st.top();
        st.pop();
        k--;
        if(k==0)break;
        root=root->left;
    }
   return root==NULL?-1:root->daa;
}














