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
    int rob(TreeNode* root) {
        int res{};
        unordered_map<TreeNode*, vector<int>> mp;
        auto search = [&](auto self, TreeNode* node) {
            if (!node) return vector<int>{0, 0};
            auto left = self(self, node->left);
            auto right = self(self, node->right);
            vector<int> v;
            v.push_back(max(left[0], left[1]) + max(right[0], right[1]));
            v.push_back(node->val + left[0] + right[0]);
            return v;
        };
        vector<int> r = search(search, root);
        return max(r[0], r[1]);
    }
};