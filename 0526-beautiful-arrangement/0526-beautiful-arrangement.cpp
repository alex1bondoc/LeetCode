class Solution {
public:
    int countArrangement(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (1 << (n + 1), -1));
        auto back = [&](auto self, int i, int mask) {
            if (i >= n) {
                if (mask == (1 << n) - 1)
                    return 1;
                return 0;
            }
            if (dp[i][mask] != -1) return dp[i][mask];
            int cnt = 0;
            for (int j{}; j < n; ++j) {
                if ((mask & (1 << j)) == 0 && ((i + 1) % (j + 1) == 0 || (j + 1) % (i + 1) == 0)) {
                    cnt += self(self,i + 1, mask | (1 << j));
                }
            }
            return cnt;
        };
        return back(back, 0, 0);
    }
};