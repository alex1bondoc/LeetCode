class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = n - 1; i >= n - k; i--) {
            ans += 1LL * mul * nums[i];
            mul = max(1, mul - 1);
        }
        return ans;
    }
};