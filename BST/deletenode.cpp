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
class Solution {
public:
    TreeNode* f(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return NULL;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else{//root->val==key;
            if(root->left==NULL and root->right==NULL){
                //leaf node;
                root=NULL;
                return root;
            }
            //1 child;
            if(root->left==NULL and root->right!=NULL){
                
                root=root->right;
                return root;
            }
            if(root->left!=NULL and root->right==NULL){
                root=root->left;
                return root;
            }
            //2 child;
            TreeNode* tmp=f(root->right);
            int tmpval=root->val;
            root->val=tmp->val;
            tmp->val=tmpval;
            
            root->right=deleteNode(root->right,key);
            return root;
            
        }
        return root;
    }
};