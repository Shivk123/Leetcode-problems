// Last updated: 5/28/2025, 9:55:25 PM
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode *t1 = headA, *t2 = headB;
        int check = 0;
        while (t1 != t2 && check<3) {
            if (t1->next == NULL) {
                t1 = headB;
                check++;
            }
            else t1=t1->next;
            if (t2->next == NULL) {
                t2 = headA;
                check++;
            }
            else t2=t2->next;
        }
        return (t1==t2)?t1:NULL;
    }
};