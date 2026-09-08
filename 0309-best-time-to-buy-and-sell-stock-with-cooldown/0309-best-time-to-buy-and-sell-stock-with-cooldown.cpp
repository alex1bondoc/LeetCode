class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>( 2, -1));
        auto back = [&](auto self, int i, int buy) {
            if (i >= n) return 0;
            if (dp[i][buy] != - 1) return dp[i][buy];
            if (buy == 0) {
                return dp[i][buy] = max(self(self, i + 1, buy), -prices[i] + self(self, i + 1, buy + 1));
            }
            else {
                return dp[i][buy] = max(self(self, i + 1, buy), prices[i] + self(self, i + 2, buy - 1));
            }
        };
        return back(back, 0, 0);
    }
};