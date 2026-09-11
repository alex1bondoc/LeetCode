class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> first;
        first[0] = -1;                          // prefixul gol e „înainte" de index 0
        int s = 0, res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            s += nums[i] == 1 ? 1 : -1;
            auto it = first.find(s);
            if (it != first.end())
                res = max(res, i - it->second); // de la primul index cu același prefix până la i
            else
                first[s] = i;                   // salvezi DOAR prima apariție
        }
        return res;
    }
};