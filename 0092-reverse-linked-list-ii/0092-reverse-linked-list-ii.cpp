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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *leftp=NULL,*rightp=NULL,*curr=head,*start;
        int count = 1;
        
        //find out right and left pointer
        if(left==right)
            return head;
        else if(left ==1)
            leftp = head;
        while(count!=right) {
            if(count+1==left and leftp==NULL)
                leftp = curr;
            curr = curr->next;
            count++;
        }
        rightp = curr->next;
        
        if(left==1)  start = leftp;
        else  start = leftp->next;

        
        //reverse
        ListNode *prev=NULL,*cur,*next;
        if(left==1) cur = leftp;
        else cur = leftp->next;

        while(cur!=rightp) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        leftp->next = prev;    
        start->next = rightp;    
        if(left==1)
            head = prev;
        return head;  
    }
};