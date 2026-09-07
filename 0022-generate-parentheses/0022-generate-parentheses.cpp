class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur{};
        auto back = [&](auto self, int open, int closed) {
            if (open == n && closed == n) {
                res.push_back(cur);
                return;
            }
            if (closed > open || open > n) return;
            cur.push_back('(');
            self(self, open + 1, closed);
            cur.pop_back();
            cur.push_back(')');
            self(self, open, closed + 1);
            cur.pop_back();
        };
        back(back, 0, 0);
        return res;

    }
};