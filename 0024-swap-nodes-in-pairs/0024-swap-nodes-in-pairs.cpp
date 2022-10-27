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
    ListNode * swap(ListNode *one, ListNode *two) {
        if(!one)
            return NULL;
        else if(!two)
            return one;
        
        ListNode *temp = two->next;
        two->next = one;
        if(!temp)
            one->next = NULL;
        else
            one->next = swap(temp,temp->next);
        return two;
    }
    
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        if(!curr or !curr->next)
            return head;
        else
            head = swap(curr,curr->next);
       
        return head;
    }
};