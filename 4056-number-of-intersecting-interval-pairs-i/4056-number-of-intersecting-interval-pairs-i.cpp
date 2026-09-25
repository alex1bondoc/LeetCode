class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        long long res{};
        for (int i{}; i < n; ++i) {
            for (int j{i + 1}; j < n; ++j) {
                if (i == j) continue;
                int start1{intervals[i][0]};
                int end1{intervals[i][1]};
                int start2{intervals[j][0]};
                int end2{intervals[j][1]};
                if (start1 <= end2 && start2 <= end1) {
                    res++;
                }
            }
        }
        return res;
    }
};