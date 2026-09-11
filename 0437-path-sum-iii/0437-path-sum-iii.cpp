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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, long long> m;
        long long res{};
        long long  s{};
        m[0] = 1;
        auto dfs = [&](auto self, TreeNode* node) {
            if (!node) return;
            s += node->val;
            res += m[s - targetSum];
            m[s] ++;
            self(self, node->left);
            self(self, node->right);
            m[s]--;
            s-=node->val;

        };
        dfs(dfs, root);
        return res;
    }
};