class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 1));
        for (int i{n - 1}; i >= 0; --i) {
            for (int j{m - 1}; j >= 0; --j) {
                if (dungeon[i][j] < 0) {
                    int maxi {1 << 30};
                    if (j < m - 1) {
                        maxi = min(maxi, dp[i][j + 1]);
                    }
                    if (i < n - 1) {
                        maxi = min(maxi, dp[i + 1][j]);
                    }
                    if (maxi == 1 << 30) maxi = 1;
                    dp[i][j] = maxi + (-dungeon[i][j]);
                }
                else if(dungeon[i][j] == 0) {
                    int maxi{1 << 30};
                    if (i < n - 1) {
                        maxi = min(maxi, dp[i + 1][j]);
                    }
                    if (j < m - 1) {
                        maxi = min(maxi, dp[i][j + 1]);
                    }
                    if (maxi == 1 << 30) maxi = 1;
                    dp[i][j] = maxi;
                }
                else {
                    int maxi{1 << 30};
                    if (j < m - 1) {
                        maxi = min(maxi, dp[i][j + 1] - dungeon[i][j]);
                    }
                    if (i < n - 1) {
                        maxi = min(maxi, dp[i + 1][j] - dungeon[i][j]);

                    }
                    if (maxi <= 0 || maxi == 1 << 30) maxi = 1;
                    dp[i][j] = maxi;
                }
            }
        }
        for (int i{}; i < n; ++i, cout << endl) {
            for (int j{}; j < m; ++j) {
                cout << dp[i][j] << " ";
            }
        }
        return dp[0][0];
    }
};