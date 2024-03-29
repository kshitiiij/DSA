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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *curr=head,*prev=NULL;
        
        while(curr and curr->next) {
            if(curr and curr->next and curr->val==curr->next->val) {
                    while(curr and curr->next and curr->val==curr->next->val) {
                        curr = curr->next;
                }
                if(prev!=NULL)
                    prev->next = curr->next;
                else
                    head = curr->next;
            }
            else
                prev = curr;
            curr = curr->next;
            
        }
        return head;
    }
};