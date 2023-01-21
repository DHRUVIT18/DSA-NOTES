/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

//109
class Solution {
public:
    //traverse same as array;
    TreeNode* function(ListNode* head,ListNode* tail){
        if(head==tail){
            return NULL;
        }
        //if linked list size is 1
        if(head->next==tail){
            TreeNode* root=new TreeNode(head->val);
            return root;
        }
        ListNode* mid=head,*tmp=head;
        //finding mid
        while(tmp!=tail and tmp->next!=tail){
            tmp=tmp->next->next;
            mid=mid->next;
        }
        TreeNode* root=new TreeNode(mid->val);
        root->left=function(head,mid);
        root->right=function(mid->next,tail);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        return function(head,NULL);
    }
    
};
