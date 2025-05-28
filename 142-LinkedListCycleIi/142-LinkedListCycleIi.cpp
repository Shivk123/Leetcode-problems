// Last updated: 5/28/2025, 9:55:29 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        do {
            if (fast!=NULL && fast->next != NULL)
                fast = fast->next->next;
            else
                return NULL;
            slow = slow->next;
        } while (slow != fast);
        fast = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};