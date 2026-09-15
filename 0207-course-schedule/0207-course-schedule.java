class Solution {
    public boolean canFinish(int n, int[][] pre) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            adj.add(new ArrayList<>());
        }
        int[] in = new int[n];
        for (int[] p : pre) {
            adj.get(p[1]).add(p[0]);
            in[p[0]]++;
        }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++)
            if (in[i] == 0) q.add(i);
        int count = 0;
        while (q.size() > 0) {
            int node = q.poll();
            count ++;
            for (int next : adj.get(node)) {
                in[next]--;
                if (in[next] == 0) q.add(next);
            }
        }


        return count == n;
    }
}