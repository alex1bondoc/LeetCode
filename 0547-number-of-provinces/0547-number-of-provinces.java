class Solution {
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        int[] visited = new int[n];
        int provinces = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == 0) {
                provinces ++;
                visited[i] = provinces;
                dfs(isConnected, visited, i, provinces, n);
            }
        }
        return provinces;
    }
    private void dfs(int[][] isConnected, int[] visited, int node, int provinces, int n) {
        for (int i = 0; i < n; ++i) {
            if (isConnected[node][i] == 1 && visited[i] == 0) {
                visited[i] = provinces;
                dfs(isConnected, visited, i, provinces, n);
            }
        }
    }
}