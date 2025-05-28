// Last updated: 5/28/2025, 9:49:46 PM
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* t=head;
        while(t->next){
            ListNode* newNode = new ListNode(__gcd(t->val,t->next->val),t->next);
            t->next=newNode;
            t=t->next->next;
        }
        return head;
    }
};