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
    int getDecimalValue(ListNode* head) {
        ListNode *curr = head;
        int num =0,p=0;
        while(curr) {
            p++;
            curr = curr->next;
        }
        curr = head;
        p--;
        while(curr) {
            num = num + (curr->val)*pow(2,p--);
            curr = curr->next;
        }
        return num;
    }
};