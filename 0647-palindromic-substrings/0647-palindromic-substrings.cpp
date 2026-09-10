class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> pals(n, vector<bool>(n));
        for (int i{n - 1}; i >= 0; --i) {
            for (int j{i}; j < n; ++j) {
                pals[i][j] = (j - i < 2 || pals[i + 1][j - 1]) && s[i] == s[j];
            }
        }
        int i{};
        vector<int> dp(s.size() + 1, 0);
        for (int i = s.size() - 1; i>=0; --i) {
            for (int j{i}; j < s.size(); ++j) {
                int res{};
                if (pals[i][j]) {
                    dp[i] += 1;
                }
            }
            dp[i] += dp[i + 1];
        }
        return dp[0];
    }
};