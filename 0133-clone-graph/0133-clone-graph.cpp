/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        unordered_set<Node*> visited;
        visited.insert(node);
        auto dfs = [&](auto self, Node* n) -> void{
            if (!mp.contains(n)) {
                mp[n] = new Node(n->val);
            }
            for (auto nei : n->neighbors) {
                if (!mp.contains(nei)) {
                    mp[nei] = new Node(nei->val);
                }
                mp[n]->neighbors.push_back(mp[nei]);
                if (visited.contains(nei)) continue;
                visited.insert(nei);
                self(self, nei);
            }
        };
        dfs(dfs, node);
        return mp[node];
    }
};