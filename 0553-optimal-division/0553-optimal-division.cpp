class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        int n = nums.size();
        vector<vector<double>> mx(n, vector<double>(n)), mn(n, vector<double>(n));
        vector<vector<int>> kMax(n, vector<int>(n)), kMin(n, vector<int>(n));

        for (int l = n - 1; l >= 0; --l) {
            mx[l][l] = mn[l][l] = nums[l];
            for (int r = l + 1; r < n; ++r) {
                mx[l][r] = -1e18; mn[l][r] = 1e18;
                for (int k = l; k < r; ++k) {            // left = [l..k], right = [k+1..r]
                    double hi = mx[l][k] / mn[k + 1][r];  // biggest / smallest
                    double lo = mn[l][k] / mx[k + 1][r];  // smallest / biggest
                    if (hi > mx[l][r]) { mx[l][r] = hi; kMax[l][r] = k; }
                    if (lo < mn[l][r]) { mn[l][r] = lo; kMin[l][r] = k; }
                }
            }
        }
        return build(nums, kMax, kMin, 0, n - 1, true);
    }

private:
    string build(vector<int>& nums, vector<vector<int>>& kMax, vector<vector<int>>& kMin,
                 int l, int r, bool wantMax) {
        if (l == r) return to_string(nums[l]);
        int k = wantMax ? kMax[l][r] : kMin[l][r];
        string left  = build(nums, kMax, kMin, l, k, wantMax);
        string right = build(nums, kMax, kMin, k + 1, r, !wantMax);  // right side flips max/min
        if (k + 1 < r) right = "(" + right + ")";
        return left + "/" + right;
    }
};