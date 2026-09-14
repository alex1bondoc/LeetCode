class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) return {};
        int start = nums[0];
        int prevEnd = nums[0];
        vector<string> res{};
        for (int i{1}; i < nums.size(); ++i) {
            if (prevEnd + 1 == nums[i]) {
                prevEnd = nums[i];
            }
            else {
                if (start != prevEnd)
                res.push_back(to_string(start) + "->" + to_string(prevEnd));
                else {
                    res.push_back(to_string(start));
                }
                start = prevEnd = nums[i];
            }
        }
        if (start != prevEnd)
                res.push_back(to_string(start) + "->" + to_string(prevEnd));
                else {
                    res.push_back(to_string(start));
                }
        return res;

    }
};