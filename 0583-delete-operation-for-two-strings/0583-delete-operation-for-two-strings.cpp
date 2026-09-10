class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return 0;
            if (i > n || j > m) return 1 << 30;
            if (dp[i][j] != -1) return dp[i][j];
            if (word1[i] == word2[j]) return dp[i][j] =self(self, i + 1, j + 1);
            else return dp[i][j] = min(self(self, i + 1, j),self(self, i, j + 1)) + 1;
        };
        return back(back, 0, 0);
    }
};