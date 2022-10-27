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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or !head)
            return head;
        else if(!head->next)
            return head;
        
        int size = 0,f=0;
        ListNode *slow=head , *fast = head,*curr=head;
        
        while(curr) {
            curr = curr->next;
            size++;
            if(f!=k) {
                fast = fast->next;
                f++;
            }
        }
        if(size==k)
            return head;
        
        if(f!=k) {
            size = k%size;
            fast =head;
            while(size) {
                fast = fast->next;
                size--;
            }
        }

        while(fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
    }
};