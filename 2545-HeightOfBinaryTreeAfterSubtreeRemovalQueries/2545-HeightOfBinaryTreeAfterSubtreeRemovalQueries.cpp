// Last updated: 5/28/2025, 9:50:47 PM
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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*, int> depthMap;

        function<int(TreeNode*)> calculateDepth = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int leftDepth = calculateDepth(node->left);
            int rightDepth = calculateDepth(node->right);
            depthMap[node] = 1 + max(leftDepth, rightDepth);
            return depthMap[node];
        };
        calculateDepth(root);

        vector<int> maximumRest(depthMap.size() + 1);

        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* node, int depth, int rest) {
            if (!node) return;
            ++depth;
            maximumRest[node->val] = rest;
          
            dfs(node->left, depth, max(rest, depth + depthMap[node->right]));
            dfs(node->right, depth, max(rest, depth + depthMap[node->left]));
        };
        dfs(root, -1, 0);

        vector<int> answers;
      
        for (int value : queries) {
            answers.push_back(maximumRest[value]);
        }
        return answers;
    }
};