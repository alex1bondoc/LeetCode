class Solution {
public:
    vector<int> temp;

    void dfs(TreeNode* root) {
        if (!root) {
            return;
        }

        dfs(root->left);
        temp.push_back(root->val);
        dfs(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        dfs(root);

        return temp[k - 1];
    }
};