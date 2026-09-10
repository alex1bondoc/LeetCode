class Solution {
public:
    int change(int amount, vector<int> coins) {
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int s{1}; s <= amount; ++s) {
                if (s - coin >= 0) {
                    dp[s] += dp[s - coin];
                }
            }
        }
        return dp[amount];
    }
};