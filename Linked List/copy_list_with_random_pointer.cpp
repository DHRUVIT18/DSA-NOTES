/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)return NULL;
        Node* curr=head;
        Node* dummy=new Node(-1);
        Node* it=dummy;
        unordered_map<Node*,Node*>mp;
        while(curr){
            
            it->next=new Node(curr->val);
            
            mp[curr]=it->next;
            curr=curr->next;
            it=it->next;
        }
        curr=head,it=dummy->next;
        while(curr){
            if(curr->random){
                it->random=mp[curr->random];
            }
            it=it->next;
            curr=curr->next;
        }
        
       
        return dummy->next;
    }
};

















