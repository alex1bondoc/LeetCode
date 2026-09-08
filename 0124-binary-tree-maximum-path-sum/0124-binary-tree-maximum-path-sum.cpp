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
    int maxPathSum(TreeNode* root) {
        auto node{root};
        TreeNode* last{};
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> m;
        int sol{1 << 31};
        while (st.size() || node) {
            if (node) {
                st.push(node);
                node = node->left;
            }
            else {
                node = st.top();
                if (node->right == last || node->right == nullptr) {
                    st.pop();
                    int left{m[node->left]};
                    int right{m[node->right]};
                    left = max(0, left);
                    right = max(0, right);
                    sol = max(sol, left + right + node->val);
                    m[node] = max(node->val + left, node->val + right);
                    last = node;
                    node = nullptr;
                }
                else {
                    node = node->right;
                }
            }
        }
        return sol;
    }
};