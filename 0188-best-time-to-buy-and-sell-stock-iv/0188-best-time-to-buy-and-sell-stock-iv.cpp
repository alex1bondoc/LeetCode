class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) return 0;

        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
        // dp[n][*] = 0 și dp[*][0] = 0 sunt deja cazurile de bază

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 1; buy <= 2 * k; ++buy) {
                if (buy % 2 == 1)   // ții acțiunea → poți vinde
                    dp[i][buy] = max(dp[i + 1][buy], prices[i] + dp[i + 1][buy - 1]);
                else                // poți cumpăra
                    dp[i][buy] = max(dp[i + 1][buy], -prices[i] + dp[i + 1][buy - 1]);
            }
        }

        return dp[0][2 * k];
    }
};