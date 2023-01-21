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
    ListNode* f(ListNode* head){
        if(!head or !head->next)return head;
        
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* tmp=f(second->next);
        first->next=tmp;
        second->next=first;
        
        return second;
        
    }
    
    ListNode* swapPairs(ListNode* head) {
       
        return f(head);
    }
};
