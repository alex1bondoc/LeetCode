class Solution {
public:
    bool makesquare(vector<int>& m) {
        int n = m.size();
        long long sum = accumulate(m.begin(), m.end(), 0LL);
        if (sum % 4) return false;
        int side = sum / 4;
        if (*max_element(m.begin(), m.end()) > side) return false;

        // dp[mask] = cât am construit din latura curentă, folosind bețele din mask
        // -1 = starea nu poate fi atinsă
        vector<int> dp(1 << n, -1);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) continue;          // bățul i e deja folosit
                if (dp[mask] + m[i] <= side)            // încape în latura curentă
                    dp[mask | (1 << i)] = (dp[mask] + m[i]) % side;  // % side = latură completă, începem alta
            }
        }
        return dp[(1 << n) - 1] == 0;
    }
};