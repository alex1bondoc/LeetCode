class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res{};
        unordered_map<int, int> count{};
        int dif{};
        int mx{};
        for (int num : nums) {
            if (!count[num]) dif++;
            count[num] ++;
            mx = max(mx, num);
        }
        while (dif) {
            for (int i{1}; i <= 100; ++i) {
                if (count[i]) {
                    count[i] --;
                    res.push_back(i);
                    if (!count[i]) {
                        dif--;
                    }
                }
            }
        }
        return res;

    }
};