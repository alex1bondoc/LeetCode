class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9], col[9], square[9];
        int n = 9;
        for (int i{}; i < n; ++i) {
            for (int j{}; j < n; ++j) {
                int sq{(i / 3) * 3+ j / 3};
                int val{board[i][j]};
                if (val == '.') continue;
                if (row[i].contains(val) || col[j].contains(val) || square[sq].contains(val))
                    return false;
                row[i].insert(val);
                col[j].insert(val);
                square[sq].insert(val);
            }
        }
        return true;
    }
};