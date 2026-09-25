class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> s, e;

        for (auto &x : intervals) {
            s.push_back(x[0]);
            e.push_back(x[1]);
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        long long res = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < n && e[j] < s[i])
                j++;

            res += (i - j);
        }

        return res;
    }
};