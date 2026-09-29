class Solution {
public:
    using ll = long long;
    ll maxEarnings(vector<vector<int>>& A) {
        sort(begin(A), end(A), [&](auto& a, auto& b) { return a[1] < b[1]; });
        
        int n = A.size();
        vector<ll> pref(n), end(n), dp(n);
        
        for(int i = 0; i < n; ++i)
            end[i] = A[i][1];
        
        for(int i = 0; i < n; ++i) {
            ll st = A[i][0], ed = A[i][1], rev = A[i][2], cur = rev;
            
            auto it = upper_bound(begin(end), begin(end) + i, st);
            int idx = (it - begin(end)) - 1;
            
            if(idx >= 0)
                cur += st + pref[idx];

            dp[i] = cur;
            if(i)
                dp[i] = max(dp[i], dp[i - 1]);
            
            pref[i] = dp[i] - ed;
            if(i)
                pref[i] = max(pref[i], pref[i - 1]);
        }
        
        return dp[n - 1];
    }
};