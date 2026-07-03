class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> v(101);
        vector<int> sol;
        for (const auto& num : nums) {
            if (v[num] < k) sol.push_back(num);
            v[num] ++; 
        }
        return sol;
    }
};