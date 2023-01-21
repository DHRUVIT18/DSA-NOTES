//235 

//just iterate in bst if both are greater than curr go to right
//else go to left
//else bingo


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    
        TreeNode* curr=root;
        while(curr){
            if(p->val>curr->val and q->val>curr->val){
                curr=curr->right;
            }else if(p->val<curr->val and q->val<curr->val){
                curr=curr->left;
            }else{
                return curr;
            }
        }
        return NULL;
    }
};