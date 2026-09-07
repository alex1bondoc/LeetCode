class Solution {
public:
    string longestPalindrome(string s) {
        int res{1};
        int start{};
        int n{static_cast<int>(s.size())};
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i{}; i < n; ++i) {
            dp[i][i] = 1;
            if (i < n - 1) {
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 1;
                    res = 2;
                    start = i;
                }
            }
        }
        for (int len{3}; len <= n; ++len) {
            for (int i{}; i <= n - len; ++i) {
                if (s[i] == s[i + len - 1] && dp[i + 1][i + len - 2]) {
                    dp[i][i + len - 1] = 1;
                    res = len;
                    start = i;
                }
            }
        }
        return s.substr(start, res);
    }
};