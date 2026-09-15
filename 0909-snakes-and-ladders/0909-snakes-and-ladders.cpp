class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto cell = [&](int num) {
            int r = (num - 1) / n, c = (num - 1) % n;
            int i = n - 1 - r;                        // numerotarea începe de jos
            int j = (r % 2 == 0) ? c : n - 1 - c;     // zigzag
            return board[i][j];
        };

        vector<int> dist(n * n + 1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            if (s == n * n) return dist[s];
            for (int d = 1; d <= 6 && s + d <= n * n; ++d) {
                int next = s + d;
                int v = cell(next);
                if (v != -1) next = v;                // scara/șarpele e obligatoriu
                if (dist[next] == -1) {
                    dist[next] = dist[s] + 1;
                    q.push(next);
                }
            }
        }
        return -1;
    }
};