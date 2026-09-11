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
    int longestZigZag(TreeNode* root) {
        int res{};
        auto dfs = [&](auto self, TreeNode* node) -> pair<int, int>{
            if (!node) return {-1, -1};
            if (!node->left && !node->right) {
                return {0, 0};
            }
            else {
                auto [leftleft, leftright] = self(self, node->left);
                auto [rightleft, rightright] = self(self, node->right);
                res = max(leftright + 1, max(res, rightleft + 1));
                return {leftright + 1, rightleft + 1};
            }
        };
        dfs(dfs, root);
        return res;
    }
};