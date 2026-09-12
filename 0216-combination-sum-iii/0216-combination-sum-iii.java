class Solution {
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> cur = new ArrayList<>();

    public List<List<Integer>> combinationSum3(int k, int n) {
        back(1, 0, k, n);
        return res;
    }

    private void back(int i, int sum, int k, int n) {
        if (cur.size() == k) {
            if (sum == n) res.add(new ArrayList<>(cur));
            return;
        }
        if (i == 10) return;

        cur.add(i);                        // take i
        back(i + 1, sum + i, k, n);
        cur.remove(cur.size() - 1);        // undo

        back(i + 1, sum, k, n);            // skip i
    }
}