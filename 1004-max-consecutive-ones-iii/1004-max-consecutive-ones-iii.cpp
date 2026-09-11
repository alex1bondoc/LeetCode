class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l{};
        int res{};
        int count{};
        for (int r{}; r < nums.size(); ++r) {
            if (nums[r] == 1) {
                count++;
            }
            while (r - l + 1 - count > k) {
                if (nums[l] == 1)
                    count --;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};