class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
        });
        int n = intervals.size();
        int res{};
        int prevEnd = intervals[0][1];
        for (int i{1}; i < n; ++i) {
            auto interval = intervals[i];
            if (interval[0] < prevEnd) {
                res++;
            }
            else {
                prevEnd = interval[1];
            }
        }
        return res;
    }
};