class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int res{};
        int n = nums.size();
        for (int num : nums) {
            if (m[num]) continue;
            m[num] = m[num + 1] + m[num - 1] + 1;
            m[num + m[num + 1]] = m[num];
            m[num - m[num - 1]] = m[num];
            res = max(m[num], res);
        }
        return res;
    }
};