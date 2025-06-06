// Last updated: 5/28/2025, 9:54:05 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        unordered_map<int, int> postToIndex;

        for (int i = 0; i < post.size(); ++i)
            postToIndex[post[i]] = i;

        return build(pre, 0, pre.size() - 1, post, 0, post.size() - 1,
                     postToIndex);
    }

private:
    TreeNode* build(const vector<int>& pre, int preStart, int preEnd,
                    const vector<int>& post, int postStart, int postEnd,
                    const unordered_map<int, int>& postToIndex) {
        if (preStart > preEnd)
            return nullptr;
        if (preStart == preEnd)
            return new TreeNode(pre[preStart]);

        const int rootVal = pre[preStart];
        const int leftRootVal = pre[preStart + 1];
        const int leftRootPostIndex = postToIndex.at(leftRootVal);
        const int leftSize = leftRootPostIndex - postStart + 1;

        TreeNode* root = new TreeNode(rootVal);
        root->left = build(pre, preStart + 1, preStart + leftSize, post,
                           postStart, leftRootPostIndex, postToIndex);
        root->right = build(pre, preStart + leftSize + 1, preEnd, post,
                            leftRootPostIndex + 1, postEnd - 1, postToIndex);
        return root;
    }
};