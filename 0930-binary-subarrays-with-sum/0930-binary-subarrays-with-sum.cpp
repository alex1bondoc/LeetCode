class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> count;
        int sum = 0, res = 0;
        count[0] = 1;
        for (auto num : nums) {
            sum += num;
            res += count[sum - goal];
            count[sum]++;
        }
        return res;
    }
};