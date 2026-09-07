class Solution {
public:
    string longestPalindrome(string s) {
        string t{"#"};
        for (char c : s) {
            t += c;
            t += '#';
        }
        int n{static_cast<int>(t.size())};
        int l{}, r{};
        vector<int> p(n);
        for (int i{}; i < n; ++i) {
            if (i < r) {
                p[i] = min(r - i, p[l + r - i]);
            }
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                r = i + p[i];
                l = i - p[i];
            }
        }
        int idx{}, maxLen{};
        for (int i{}; i < n; ++i) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                idx = i;
            }
        }
        return s.substr((idx - maxLen) / 2, maxLen);
    }
};