class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l{};
        int haveZero{};
        int res{};
        for (int r{}; r < n; ++r) {
            if (nums[r] == 0 && !haveZero) {
                haveZero = 1;
            }
            else if (nums[r] == 0 && haveZero) {
                while (haveZero) {
                    if (nums[l] == 0) haveZero = 0;
                    l++;
                }
                haveZero = 1;
            }
            res = max(res, r - l + 1);

        }
        return res - 1;
    }
    
};