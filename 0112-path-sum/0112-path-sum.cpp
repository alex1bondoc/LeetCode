class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>> st;
        if (root) st.push({root, 0});
        while (st.size()) {
            auto [node, s] = st.top();
            st.pop();
            s += node->val;
            if (!node->left && !node->right) {      // frunză: aici se verifică
                if (s == targetSum) return true;
                continue;
            }
            if (node->left)  st.push({node->left, s});
            if (node->right) st.push({node->right, s});
        }
        return false;
    }
};