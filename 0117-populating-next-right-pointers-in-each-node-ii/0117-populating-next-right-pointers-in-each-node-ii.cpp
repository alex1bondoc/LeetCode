/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        std::queue<Node*> q;
        if (root) q.push(root);
        while (q.size()) {
            std::queue<Node*> q2;
            int n = q.size();
            for (int i{}; i < n; ++i) {
                auto node = q.front();
                q.pop();
                if (q.size()) {
                    node->next = q.front();
                }
                auto left = node->left;
                auto right = node->right;
                if (left) q2.push(left);
                if (right) q2.push(right);
            }
            q = q2;
        }
        return root;
    }
};