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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr=head->next,*first=head->next;
        int sum=0;
        while(curr) {
            if(sum==0)
                first = curr;
            if(curr->val==0 and curr!=head) {
                first->val = sum;
                first->next = curr->next;
                sum =0;
            }
            else 
                sum += curr->val;
            
            curr = curr->next;
        }
        
        return head->next;
    }
};