class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        int n = s.size();
        int maxLen = 0;
        for (auto& str : wordDict) {
            maxLen = max(maxLen, static_cast<int>(str.size()));
        }
        vector<string> res;
        vector<string> cur; 
        vector<int> dp(s.size() + 1, -1);
        auto back = [&](auto self, int i) {
            if (i == n) {
                string m{};
                for (string c : cur) {
                    m += c;
                    m += " ";
                }
                m.pop_back();
                res.push_back(m);
                return ;
            }
            for (int j{1}; j <= maxLen && i + j <= n; ++j) {
                if (set.contains(s.substr(i, j))) {
                    cur.push_back(s.substr(i, j));
                    self(self, i + j);
                    cur.pop_back();
                }
            }
        };

        back(back, 0);
        return res;
    }
};