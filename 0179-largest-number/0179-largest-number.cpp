class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int zeros{};
        for (int num : nums) {
            zeros += num == 0;
        }
        if (zeros == nums.size()) return "0";
        std::sort(nums.begin(), nums.end(), [](auto a, auto b) {
            string sa{to_string(a)}, sb{to_string(b)};
            return sa + sb > sb + sa;
        });
        string res{};
        for (auto num : nums) {
            res += to_string(num);
        }
        return res;
    }
};