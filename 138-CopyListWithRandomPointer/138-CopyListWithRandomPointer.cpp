// Last updated: 5/28/2025, 9:55:30 PM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return nullptr;
        Node *ans=new Node(0), *temp = head, *current;
        while (temp != NULL) {
            Node* copy_node = new Node(temp->val);
            copy_node->next = temp->next;
            temp->next = copy_node;
            temp = temp->next->next;
        }
        temp = head;
        while (temp != NULL) {
            current = temp->next;
            current->random =
                (temp->random != nullptr) ? temp->random->next : nullptr;
            temp = temp->next->next;
        }
        temp = head;
        current=ans;
        while (temp != NULL) {
            current->next=temp->next;
            temp->next=temp->next->next;
            temp=temp->next;
            current=current->next;
        }
        return ans->next;
    }
};