class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp (n, vector<int>(m, -1));
        auto back = [&](auto self, int i, int j){
            if (i >= n || j >= m) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            if (text1[i] == text2[j]) {
                return dp[i][j] = self(self, i + 1, j + 1) + 1;
            }
            else {
                return dp[i][j] =max(self(self, i + 1, j), self(self, i, j + 1));
            }
        };
        return back(back, 0, 0);
    }
};