class Solution {
    public int minReorder(int n, int[][] connections) {
        List<Integer>[] out = new ArrayList[n];   // drumuri care pleacă din nod
        List<Integer>[] in  = new ArrayList[n];   // drumuri care intră în nod
        for (int i = 0; i < n; i++) {
            out[i] = new ArrayList<>();
            in[i]  = new ArrayList<>();
        }
        for (int[] c : connections) {
            out[c[0]].add(c[1]);
            in[c[1]].add(c[0]);
        }

        boolean[] visited = new boolean[n];
        visited[0] = true;
        return dfs(out, in, visited, 0);
    }

    private int dfs(List<Integer>[] out, List<Integer>[] in, boolean[] visited, int node) {
        int cnt = 0;
        for (int nei : out[node]) {
            if (visited[nei]) continue;
            visited[nei] = true;
            cnt += 1 + dfs(out, in, visited, nei);   // orientată dinspre 0: trebuie inversată
        }
        for (int nei : in[node]) {
            if (visited[nei]) continue;
            visited[nei] = true;
            cnt += dfs(out, in, visited, nei);       // orientată spre 0: e deja bine
        }
        return cnt;
    }
}