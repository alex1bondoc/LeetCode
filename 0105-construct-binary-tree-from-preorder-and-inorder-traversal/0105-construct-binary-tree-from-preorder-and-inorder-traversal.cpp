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
        int i{}, j{}, n = preorder.size();
        auto head = new TreeNode{};
        auto node = head;
        while (i < n && j < n) {
            node->right = new TreeNode(preorder[i], nullptr, node->right);
            node = node->right;
            i ++;
            while (i < n && node->val != inorder[j]) {
                node->left = new TreeNode{preorder[i], nullptr, node};
                node = node->left;
                i++;
            }
            j ++;
            while (j < n && node->right && node->right->val == inorder[j]) {
                auto help = node->right;
                node->right = nullptr;
                j++;
                node = help;
            }
        }
        return head->right;
    }
};