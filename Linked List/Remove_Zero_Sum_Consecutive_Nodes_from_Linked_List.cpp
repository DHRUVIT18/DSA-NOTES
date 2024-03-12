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
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
       ListNode* dummy= new ListNode(0);
        dummy->next=head;
        ListNode* curr=dummy;
        int presum=0;
        unordered_map<int,ListNode*>mp;
        mp[0]=dummy;
        while(curr){
            presum+=curr->val;
            mp[presum]=curr;
            curr=curr->next;
        }
        presum=0;
        curr=dummy;
        while(curr){
            presum+=curr->val;
            curr->next=mp[presum]->next;
            curr=curr->next;
        }
        return dummy->next;
    }
};