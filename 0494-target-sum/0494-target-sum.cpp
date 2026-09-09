class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum{};
        for (int num : nums) {
            if (num < 0) sum += -num;
            sum += num;
        }
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum * 2 + 1, -1));
        auto back = [&](auto self, int i, int s) {
            if (i == n) {
                if (s == target) return 1;
                return 0;
            }
            if (dp[i][s + sum] != -1) return dp[i][s + sum];
            int num = nums[i];
            return dp[i][s + sum] = (self(self, i + 1, s - num) +  self(self, i + 1, s + num));
        };
        return back(back, 0, 0);
    }
};