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
     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n{static_cast<int>(preorder.size())};
        int p{}, i{};
        auto dfs = [&](auto self, int limit) -> TreeNode*{
            if (p >= n) return nullptr;
            if (limit == inorder[i]) {
                i++;
                return nullptr;
            }
            auto root = new TreeNode(preorder[p++]);
            root->left = self(self, root->val);
            root->right = self(self, limit);
            return root;
        };
        return dfs(dfs, INT_MAX);
     }
};