class Solution {
public:
    int maxArea(vector<int>& height) {
        int res{};
        int l{}, r{static_cast<int>(height.size() - 1)};
        while (l < r) {
            if (height[l] < height[r]) {
                res = max(res, height[l] * (r - l));
                l++;
            }
            else {
                res = max(res, height[r] * (r - l));
                r--;
            }
        }
        return res;
    }
};