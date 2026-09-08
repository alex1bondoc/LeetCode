class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        if (n + m != s3.size()) return false;
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return true;
            if (i > n || j > m) return false;
            if (dp[i][j] != -1) return dp[i][j] == 1;
            bool res{};
            if (s1[i] == s3[i + j]) {
                res = res || self(self, i + 1, j);
            }
            if (s2[j] == s3[i + j]) {
                res = res || self(self, i, j + 1);
            }
            dp[i][j] = res;
            return res;
        };
        return back(back, 0, 0);
    }
};