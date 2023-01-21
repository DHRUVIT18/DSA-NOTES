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
//993 leetcode
class Solution {
public:
  
    //cousins if they have same depth with diffrent parents;
   void f(TreeNode* root,int x,int y,int depth,int lvl[2],int parents[2],int currparent){
       if(!root){
           return;
       } 
       if(root->val==x){
           lvl[0]=depth;
           parents[0]=currparent;
       }
        if(root->val==y){
           lvl[1]=depth;
           parents[1]=currparent;
       }
       f(root->left,x,y,depth+1,lvl,parents,root->val);
        f(root->right,x,y,depth+1,lvl,parents,root->val);

    }
    
    bool isCousins(TreeNode* root, int x, int y) {
      int lvl[2]={-1,-1};
      int parents[2]={-1,-1};
        f(root,x,y,0,lvl,parents,-1);
        if(lvl[0]==lvl[1] and parents[0]!=parents[1]){
            return true;
        }
        return false;
    }
};