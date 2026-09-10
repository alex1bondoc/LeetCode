class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n, vector<int> (n, -1));
        auto back = [&](auto self, int i, int buffer) {
            if (i == n) {
                return 0;
            }
            if (i > n) return 1 << 30;
            if (dp[i][buffer] != -1) return dp[i][buffer];
            if (buffer== 0) {
                return dp[i][buffer] = self(self, i, i) + 1;
            }
            else {
                int res = self(self, i + buffer, buffer) + 1;
                if (i != buffer) {
                    res = min(self(self, i, i) + 1, res);
                }
                return dp[i][buffer] = res;
            }
        };
        return back(back, 1, 0);
    }
};