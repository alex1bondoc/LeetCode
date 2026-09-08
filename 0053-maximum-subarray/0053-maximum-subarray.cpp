#include <limits>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum{};
        int res{std::numeric_limits<int>::min()};
        for (int num : nums) {
            if (sum < 0) sum = 0;
            sum += num;
            res = max(sum, res);
        }
        return res;
    }
};