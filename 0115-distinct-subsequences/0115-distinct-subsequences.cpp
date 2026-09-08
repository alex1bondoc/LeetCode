class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return 1;
            if (i > n || j > m) return 0;
            int res{};
            if (dp[i][j] != -1) return dp[i][j];
            if (s[i] == t[j]) {
                res += self(self, i + 1, j + 1) + self(self, i + 1, j);
            }
            else {
                res += self(self, i + 1, j);
            }
            dp[i][j] = res;
            return res;
        };
        return back(back, 0, 0);
    }
};