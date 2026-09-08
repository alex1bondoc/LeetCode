class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int n = s.size();
        int maxLen = 0;
        for (auto& str : wordDict) {
            maxLen = max(maxLen, static_cast<int>(str.size()));
        }
        vector<int> dp(s.size() + 1, -1);
        auto back = [&](auto self, int i) {
            if (i == n) return true;
            if (dp[i] != -1) return dp[i] == 1;
            bool res = false;
            for (int j{1}; j <= maxLen && i + j <= n; ++j) {
                if (set.contains(s.substr(i, j))) {
                    cout << s.substr(i, j) << endl;
                    res = res || self(self, i + j);
                }
            }
            dp[i] = res;
            return res;
        };

        return back(back, 0);
    }
};