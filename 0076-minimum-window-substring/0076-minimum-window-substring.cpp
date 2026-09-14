#include <limits>
class Solution {
public:
    string minWindow(string s, string t) {
        int need{};
        unordered_map<char, int> freq, freq2;
        for (char c : t) {
            if (freq[c] == 0) need++;
            freq[c]++;
        }
        int l{};
        int start{-1};
        int len{std::numeric_limits<int>::max()};

        for (int r{}; r < s.size(); ++r) {
            char c{s[r]};
            freq2[c]++;
            if (freq.contains(c) && freq2[c] == freq[c]) need --;
            while (need == 0) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
                freq2[s[l]]--;
                if (freq.contains(s[l]) && freq2[s[l]] == freq[s[l]] - 1) {
                    need ++;
                }
                l++;
            }
        }
        return (start != -1) ? s.substr(start, len) : ""; 
    }
};
