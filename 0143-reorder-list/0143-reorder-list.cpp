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
    ListNode *slow,*fast;
    ListNode *rec(ListNode *curr) {
        if(fast) {
            if(curr==slow->next)
                return slow;
        }
        else {
            if(curr==slow) 
                return slow;
        }
        
        ListNode *temp,*next=NULL;
        next = curr->next;
        temp = rec(curr->next);
        slow = slow->next;
        curr->next = temp;
        if(temp==next or curr==temp)
            temp->next=NULL;
        else
            temp->next = next;
        return slow;
        
    }
    void reorderList(ListNode* head) {
        slow=head;
        fast=head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        rec(head);
        
    }
};