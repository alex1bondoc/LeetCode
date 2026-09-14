class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i{};
        while (i < n && nums[i] <= 0) {
            int target = - nums[i];
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum > target) {
                    right --;
                }
                else if (sum < target) {
                    left ++;
                }
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    right --;
                    while (left < right && nums[right] == nums[right + 1]) {
                        right --;
                    }
                }
            }
            i ++;
            while (i < n && nums[i - 1] == nums[i]) {
                i++;
            }
        }
        return res;
    }
};