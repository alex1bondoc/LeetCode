class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        auto go = [&](auto self, int i, int j) -> bool {
            if (j == m) return i == n;
            if (memo[i][j] != -1) return memo[i][j];

            bool res;
            if (p[j] == '*') {
                // '*' consumă zero caractere, sau exact unul și rămâne activ
                res = self(self, i, j + 1) || (i < n && self(self, i + 1, j));
            } else {
                res = (i < n) && (s[i] == p[j] || p[j] == '?')
                      && self(self, i + 1, j + 1);
            }
            return memo[i][j] = res;
        };

        return go(go, 0, 0);
    }
};