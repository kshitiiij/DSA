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
    int size=0;
    
    ListNode *rev(ListNode *prev, ListNode *curr, int k) {
        ListNode *next=NULL,*temp = curr;
        if(size<k)
            return temp;
        int count = k;
        while(count>0 and curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        size -=k;
        if(next) {
            temp->next = rev(NULL,curr,k);
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        ListNode* curr=head;
        while(curr) {
            curr=curr->next; size++;
        }
        head = rev(NULL,head,k);
        return head;
    }
};