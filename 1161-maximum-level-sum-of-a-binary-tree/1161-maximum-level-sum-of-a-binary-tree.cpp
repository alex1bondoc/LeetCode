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
    int maxLevelSum(TreeNode* root) {
        int res{-1};
        int mx{1 << 31};
        std::queue<TreeNode*> q;
        if (root) q.push(root);
        auto level = 1;
        while(q.size()) {
            int n = q.size();
            int sum = 0;
            for (int i{}; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                sum += node->val;
            }
            if (sum > mx) {
                mx = sum;
                res = level;
            }
            level ++;
        }
        return res;
    }
};