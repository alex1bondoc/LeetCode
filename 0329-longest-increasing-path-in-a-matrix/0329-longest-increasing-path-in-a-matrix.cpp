class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res{};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        auto dfs = [&](auto self, int i, int j, int val) {
            if (i < 0 || j < 0 || i >=n || j >= m || matrix[i][j] <= val) {
                return -1;
            }
            if (dp[i][j] != -1) return dp[i][j];
            
            int val1{matrix[i][j]};
            dp[i][j] = 1;
            dp[i][j] = max(dp[i][j], self(self, i + 1, j, val1) + 1);
            dp[i][j] = max(dp[i][j], self(self, i - 1, j, val1) + 1);
            dp[i][j] = max(dp[i][j], self(self, i, j + 1, val1) + 1);
            dp[i][j] = max(dp[i][j], self(self, i, j - 1, val1) + 1);
            return dp[i][j];

        };
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                res = max(res, dfs(dfs, i, j, -1));
            }
        }
        return res;
    }
};