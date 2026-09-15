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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int p = n - 1;
        int i = 0;
        unordered_map<int, int> m;
        for (int j{}; j < n; ++j) {
            m[inorder[j]] = j;
        }
        auto dfs = [&](auto self, int left, int right) ->TreeNode*{
            if (left > right) {
                return nullptr;
            }
            auto root = new TreeNode(postorder[p -- ]);
            root->right = self(self, m[root->val] + 1, right);
            root->left = self(self, left, m[root->val] -1 );

            return root;
        };
        return dfs(dfs, 0, n - 1);
    }
};