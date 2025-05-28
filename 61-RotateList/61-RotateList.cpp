// Last updated: 5/28/2025, 9:55:50 PM
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
        if(!head || !head->next || k==0)return head;
        ListNode *temp = head, *ans = new ListNode();
        int n = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            n++;
        }
        temp->next=head;
        k=k%n;
        k=n-k;
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};