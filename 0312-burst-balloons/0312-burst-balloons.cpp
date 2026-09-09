class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 2, 1);
        for (int i{}; i < n; ++i) {
            v[i + 1] = nums[i];
        }

        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        for (int l{n}; l >= 1; --l) {
            for (int r{l}; r <= n; ++r) {
                for (int k{l}; k <= r; ++k) {
                    dp[l][r] = max(dp[l][r], dp[l][k - 1] + dp[k + 1][r] + v[k] * v[l - 1] * v[r + 1]);
                }
            }
        }
        return dp[1][n];

    }
};