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
    ListNode* reverse(ListNode* head){
        if(!head)return head;
        ListNode* curr=head,*prev=NULL,*nex=NULL;
        while(curr){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       int currlen=1;
       if(head==NULL)return head;
        ListNode* curr=head;
        while(curr->next!=NULL and currlen<k){
            curr=curr->next;
            currlen++;
        }
        //rem nodes is less than k no need to swap;
        if(currlen<k)return head;
        
        //hold next list
        ListNode* tmp=curr->next;
        curr->next=NULL;
        
        ListNode* tmplist=reverseKGroup(tmp,k);
        ListNode* prev=reverse(head);
        
        head->next=tmplist;
        
        return prev;
    }
};










