class Solution {
public:
    bool isMatch(string s, string p) {
        int n{static_cast<int>(s.size())}, m{static_cast<int>(p.size())};
        unordered_map<string, bool> mp;
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return true;
            if (i > n || j > m) return false;

            string help{};
            help += to_string(i) + "," + to_string(j);
            if (mp.contains(help)) return mp[help];
            bool res{false};
            if (j >= m - 1 || p[j + 1] != '*') {
                if (s[i] == p[j] || p[j] == '.') {
                    res = res || self(self, i + 1, j + 1);
                }
            }
            else {
                res = res || self(self, i, j + 2);
                int k{i};
                while (res == false && k < n && (p[j] == '.' || s[k] == p[j]) ) {
                    res = res || self(self, k + 1, j);
                    k ++;
                }
            }
            mp[help] = res;
            return res;
        };

        return back(back, 0, 0);
    }
};