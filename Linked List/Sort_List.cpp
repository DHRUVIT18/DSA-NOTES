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
    ListNode* mergelist(ListNode* l1,ListNode* l2){
        ListNode* ptr=new ListNode(0);
        ListNode* curr=ptr;
        while(l1!=NULL and l2!=NULL){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=NULL){
            curr->next=l1;
            l1=l1->next;
        }
         if(l2!=NULL){
            curr->next=l2;
            l2=l2->next;
        }
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        auto slow=head,fast=head;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        auto tmp=slow->next;
        slow->next=NULL;
        auto l1=sortList(head);
        auto l2=sortList(tmp);
        return mergelist(l1,l2);
    }
};