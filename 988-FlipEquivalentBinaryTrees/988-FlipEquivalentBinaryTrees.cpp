// Last updated: 5/28/2025, 9:53:59 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return isFlipEquivalent(root1, root2);
    }

    bool isFlipEquivalent(TreeNode* root1, TreeNode* root2) {
        if (root1 == root2) return true;

        if (!root1 || !root2 || root1->val != root2->val) return false;
        return (isFlipEquivalent(root1->left, root2->left) && isFlipEquivalent(root1->right, root2->right)) ||
               (isFlipEquivalent(root1->left, root2->right) && isFlipEquivalent(root1->right, root2->left));
    }
};