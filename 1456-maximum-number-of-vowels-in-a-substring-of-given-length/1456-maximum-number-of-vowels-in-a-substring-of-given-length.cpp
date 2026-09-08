class Solution {
public:
    int maxVowels(string s, int k) {
        int res{};
        unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
        int count{};
        int l{};
        for (int r{}; r < s.size(); ++r) {
            if (st.contains(s[r])) {
                count++;
            }
            if (r >= k) {
                if (st.contains(s[l]))
                    count --;
                l++;
            }
            if (count > res) res = count;
        } 
        return res;
    }
};