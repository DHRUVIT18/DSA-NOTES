/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//only  best possible method

class Solution {
public:
    bool solve(TreeNode* root,int k,unordered_set<int>&s){
        if(!root)return  false;
        if(s.count(k-root->val))return true;
        s.insert(root->val);
        return solve(root->left,k,s) or solve(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k) {
      unordered_set<int>s;
        return solve(root,k,s);
    }
};