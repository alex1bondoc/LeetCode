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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        root->right = invertTree(root->right);
        return isSameTree(root->left, root->right); 
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && ! q) return true;
        if (!p && q) return false;
        if (p && !q) return false;
        return p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        swap(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};