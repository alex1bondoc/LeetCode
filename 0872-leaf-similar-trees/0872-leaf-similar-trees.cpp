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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> v1, v2;
        auto dfs = [&](auto self, TreeNode* node, vector<TreeNode*>& v) -> void{
            if (node->left) {
                self(self, node->left, v);
            }
            if (node->right) {
                self(self, node->right, v);
            }
            if (!node->left && !node->right) {
                v.push_back(node);
            }
        };
        dfs(dfs, root1, v1);
        dfs(dfs, root2, v2);
        if (v1.size() != v2.size()) return false;
        for (int i{}; i < v1.size(); ++i) {

            if (v1[i]->val != v2[i]->val) return false;
        }
        return true;
    }
};