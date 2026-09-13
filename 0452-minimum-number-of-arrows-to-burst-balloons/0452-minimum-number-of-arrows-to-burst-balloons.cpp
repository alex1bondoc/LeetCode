class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int n = points.size();
        int prevEnd = points[0][1];
        int res = 1;
        for (int i{}; i < n; ++i) {
            auto& p = points[i];
            if (p[0] > prevEnd) {
                res ++;
                prevEnd = p[1];
            }
        }
        return res;
    }
};