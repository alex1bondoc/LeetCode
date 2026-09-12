class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> q = new ArrayDeque<>();
        int cnt = 0;
        int res = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[0].length; ++j) {
                if (grid[i][j] == 2) {
                    q.add(new int[]{i, j});
                    grid[i][j] = 0;
                }
                else if (grid[i][j] == 1) cnt ++;
            }
        }
        int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (q.size() > 0 && cnt != 0) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                int[] node = q.remove();
                int x = node[0];
                int y = node[1];
                for (int[] d : dir) {
                    int xx = x + d[0];
                    int yy = y + d[1];
                    if (xx >= 0 && yy >= 0 && xx < grid.length && yy < grid[0].length && grid[xx][yy] == 1) {
                        q.add(new int[]{xx, yy});
                        grid[xx][yy] = 0;
                        cnt--;
                    }
                }
            }
            res++;
        }
        return cnt == 0 ? res : -1;
    }
}