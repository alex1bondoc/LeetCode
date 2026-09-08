class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        auto back = [&](auto self, int i) {
            if (i >= n) {
                return 0;
            }
            if (m.contains(i)) {
                return m[i];
            }
            
            return m[i] = max(self(self, i + 1), self(self, i + 2) + nums[i]);
        };

        return back(back, 0);
    }
};