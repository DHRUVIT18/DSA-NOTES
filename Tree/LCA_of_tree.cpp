/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool func(TreeNode* root,vector<int>&arr,int target){
        if(!root)return false;
        arr.push_back(root->val);
        if(root->val==target){
            return true;
        }
        if(func(root->left,arr,target) or func(root->right,arr,target)){
            return true;
        }
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       vector<int>p1;
        vector<int>p2;
        func(root,p1,p->val);
        func(root,p2,q->val);
        int a1=0,a2=0;
       int ans=0;
       while(a1<p1.size() and a2<p2.size()){
           if(p1[a1]==p2[a2]){
               ans=p1[a1];
               break;
           }
           a1++;
           a2++;
       }
        return new TreeNode(ans);
    }
};