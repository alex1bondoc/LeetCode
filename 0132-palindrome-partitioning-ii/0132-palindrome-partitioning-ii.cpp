class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // pal[i][j] = s[i..j] e palindrom
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i)
            for (int j = i; j < n; ++j)
                pal[i][j] = (s[i] == s[j]) && (j - i < 2 || pal[i + 1][j - 1]);

        // dp[i] = numărul minim de tăieturi pentru s[i..n-1]
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (!pal[i][j]) continue;
                if (j == n - 1) {
                    dp[i] = min(dp[i], 0);      // ultima bucată, fără tăietură
                } else if (dp[j + 1] != INT_MAX) {
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }

        return dp[0];
    }
};