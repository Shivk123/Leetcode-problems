// Last updated: 5/28/2025, 9:56:13 PM
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans=new ListNode(),*current=ans,*left=ans,*right=ans;
        ans->next=head;
        int n=0;
        while(current->next!=NULL){
            n++;
            current=current->next;
        }
        while(n>=k){
            current=left->next;
            right=current->next;
            for(int i=1;i<k;i++){
                current->next=right->next;
                right->next=left->next;
                left->next=right;
                right=current->next;
            }
            left=current;
            n-=k;
        }
        return ans->next;
    }
};