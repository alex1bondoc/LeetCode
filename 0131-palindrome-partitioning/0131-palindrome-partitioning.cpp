class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        auto back = [&](auto self, int i) {
            if (i == n) return vector<vector<string>>{{}};
            vector<vector<string>> r;
            for (int j{i}; j < n; ++j) {
                if (isPal(s.substr(i, j - i + 1))) {
                    auto l = self(self, j + 1);
                    for (int k{}; k < l.size(); ++k) {
                        reverse(l[k].begin(), l[k].end());
                        l[k].push_back(s.substr(i, j - i + 1));
                        reverse(l[k].begin(), l[k].end());
                        r.push_back(l[k]);
                    }
                }
            }
            return r;
        };
        return back(back, 0);
    }
private: 
    bool isPal(string s) {
        for (int i{}; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i - 1]) return false;
        }
        return true;
    }
};