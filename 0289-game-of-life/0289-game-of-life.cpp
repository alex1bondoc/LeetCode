class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dir{{1,0},{1,1},{1,-1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1}};
        int n = board.size(), m = board[0].size();
        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                int cnt = 0;
                for (auto& d : dir) {
                    int ii = d[0] + i, jj = d[1] + j;
                    if (ii >= 0 && ii < n && jj >= 0 && jj < m)
                        if (board[ii][jj] == 1 || board[ii][jj] == 2) cnt++;
                }
                if (cnt < 2 && board[i][j] == 1) board[i][j] = 2;
                if (cnt > 3 && board[i][j] == 1) board[i][j] = 2;
                if (board[i][j] == 0 && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i{}; i < n; ++i)
            for (int j{}; j < m; ++j)
                board[i][j] %= 2;
    }
};