class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res{};
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });
        int start = intervals[0][0];
        int prevEnd = intervals[0][1];
        int n = intervals.size();
        for (int i{1}; i < n; ++i) {
            if (intervals[i][0] <= prevEnd) {
                prevEnd = max(intervals[i][1], prevEnd);
                start = min(start, intervals[i][0]);
            }
            else {
                res.push_back({start, prevEnd});
                start = intervals[i][0];
                prevEnd = intervals[i][1];
            }
        }
        if (res.size() == 0 || prevEnd != res.back()[1]) {
            res.push_back({start, prevEnd});
        }
        return res;
    }
};