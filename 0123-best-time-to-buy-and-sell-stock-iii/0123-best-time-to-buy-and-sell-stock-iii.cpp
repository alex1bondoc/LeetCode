class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));

        // dp[n][*] = 0 deja, e cazul de bază

        for (int i = n - 1; i >= 0; --i) {
            for (int buy = 1; buy <= 4; ++buy) {
                if (buy == 4 || buy == 2)
                    dp[i][buy] = max(dp[i + 1][buy], dp[i + 1][buy - 1] - prices[i]);
                else
                    dp[i][buy] = max(dp[i + 1][buy], dp[i + 1][buy - 1] + prices[i]);
            }
        }

        return dp[0][4];
    }
};