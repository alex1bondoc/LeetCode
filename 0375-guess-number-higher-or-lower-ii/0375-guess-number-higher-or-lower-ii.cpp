class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        auto back = [&](auto self, int l, int r) {
            if (l >= r) return 0;
            int res{1 << 30};
            if (dp[l][r] != -1) return dp[l][r];
            for (int i{l}; i <= r; ++i) {
                res = min(res, max(self(self, l, i - 1), self(self, i + 1, r)) + i);
            }
            return dp[l][r] = res;
        };
        return back(back, 1, n);
    }
};