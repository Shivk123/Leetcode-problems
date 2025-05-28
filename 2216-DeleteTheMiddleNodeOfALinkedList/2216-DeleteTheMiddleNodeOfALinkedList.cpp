// Last updated: 5/28/2025, 9:51:37 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* t = head;
        int i=0;
        while(t-> next != NULL){
            i++;
            t=t->next;
        }
        int j=(i/2)+(i%2) - 1;
        i=j;
        t=head;
        cout<<i;
        while(j-- && j>-1){
            t=t->next;
        }
        if(i!=-1)t->next=t->next->next;
        else head = NULL;
        return head;
    }
};