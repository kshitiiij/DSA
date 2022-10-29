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
    
    ListNode *rev(ListNode *prev, ListNode *curr, int k) {
        if(!curr)
            return curr;
        ListNode *size = curr;
        int s=0;
        while(size) {
            size = size->next;
            s++;
        }
        
        
        
      
        ListNode *next=NULL,*temp = curr;
        if(s<k)
            return temp;
        int count = k;
        while(count>0 and curr) {
            cout<<curr->val<<" ";
            next = curr->next;
            // if(!next and count>0)
            //     return temp;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }
        if(next) {
            // cout<<curr->val<<" "<<curr->next->val<<endl;
            temp->next = rev(NULL,curr,k);
        }
        return prev;
        // return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        head = rev(NULL,head,k);
        return head;
    }
};