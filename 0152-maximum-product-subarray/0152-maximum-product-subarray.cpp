class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res{1 << 31};
        int mini{1}, maxi{1};
        for (int num : nums) {
            int old = mini;
            mini = min(num, min(mini * num, maxi * num));
            maxi = max(num, max(old * num, maxi * num));
            res = max(res, maxi);
        }
        return res;
    }
};