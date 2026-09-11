class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum{};
        int res{};
        unordered_map<int, int> count;
        count[0] = 1;
        for (auto num : nums) {
            sum += num;
            sum = ((sum % k) + k) % k;
            if (count.contains(sum)) res += count[sum];
            count[sum] ++;
        }
        return res;
    }
};