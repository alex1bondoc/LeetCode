class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> c;
        unordered_map<int, int> cnt;
        for (int num : arr) {
            cnt[num] ++;
        }
        for (const auto& [key, val] : cnt) {
            if (c.count(val)) return false;
            c.insert(val);
        }
        return true;
    }
};