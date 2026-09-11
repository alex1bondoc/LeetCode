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
    int goodNodes(TreeNode* root) {
        auto dfs = [&](auto self, TreeNode* node, int mx) {
            if (!node) return 0;
            int res{};
            if (node->val >= mx) {
                res++;
            }
            return res + self(self, node->left, max(mx, node->val)) + self(self, node->right, max(mx, node->val));
        };
        return dfs(dfs, root, -10001);
    }
};