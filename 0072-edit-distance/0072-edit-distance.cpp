class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        unordered_map<string, int> mp;
        auto back = [&](auto self, int i, int j) {
            if (i == n && j == m) return 0;
            if (i > n || j > m) return 1 << 30;
            int res = 1 << 30;
            string key{};
            key = to_string(i) + "," + to_string(j);
            if (mp.contains(key)) return mp[key];
            if (word1[i] == word2[j]) {
                res = min(res, self(self, i + 1, j + 1));
            }
            else {
                res = min(res, self(self, i + 1, j + 1) + 1) ;
                res = min(res, self(self, i + 1, j) + 1);
                res = min(res, self(self, i, j + 1) + 1);
            }
            mp[key] = res;
            return res;
        };
        return back(back, 0, 0);
    }
};