class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp (m + 1, vector<vector<int>> (n + 1, vector<int> (maxMove + 1, -1)));
        int inf = pow(10, 9) + 7;
        auto back = [&](auto self, int i, int j, int moves) {
            if (i < 0 || j <0 || i >= m || j >=n) return 1;
            if (moves == maxMove) return 0;
            if (dp[i][j][moves] != -1) return dp[i][j][moves];
            return dp[i][j][moves] = (((self(self, i + 1, j, moves + 1) % inf + self(self, i - 1, j, moves + 1)) % inf+ self(self, i, j - 1, moves + 1)) % inf+ self(self, i, j + 1, moves + 1)) % inf; 

        };
        return back(back, startRow, startColumn, 0);
    }
};