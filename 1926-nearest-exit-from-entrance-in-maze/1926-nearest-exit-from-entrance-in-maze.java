class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int[][] dist = new int[maze.length][maze[0].length];
        for (int i = 0; i < maze.length; ++i) {
            for (int j = 0; j < maze[0].length; ++j) {
                if (maze[i][j] == '+') {
                    dist[i][j] = -1;
                }
                else dist[i][j] = 1 << 30;
            } 
        }
        Queue<int[]> q = new ArrayDeque<>();
        q.add(entrance);
        dist[entrance[0]][entrance[1]] = 0;
        int[][] dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (q.size() > 0) {
            int[] node = q.remove();
            int x = node[0];
            int y = node[1];
            // System.out.println(x + " " + y);
            for (int[] d : dir) {
                int xx = node[0] + d[0];
                int yy = node[1] + d[1];
                if (xx >= 0 && xx < maze.length && yy >= 0 && yy < maze[0].length && dist[xx][yy] != -1&&dist[xx][yy] > dist[x][y] + 1) {
                    dist[xx][yy] = dist[x][y] + 1;
                    if (xx == 0 || xx == maze.length - 1 || yy == 0 || yy == maze[0].length - 1) {
                        return dist[xx][yy];
                    }
                    q.add(new int[]{xx, yy});
                }

            }
        }
        return -1;
        
    }
}