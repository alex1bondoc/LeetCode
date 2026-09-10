class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](auto p1, auto p2) {
            if (p1[1] != p2[1]) return p1[1] < p2[1];
            return p1[0] < p2[0];
        });
        vector<int> sol{pairs[0][1]};
        for (int i{1}; i < pairs.size(); ++i) {
            int k = pairs[i][0];
            if (k > sol.back()) {
                sol.push_back(pairs[i][1]);
            } 
            else {
                int idx = lower_bound(sol.begin(), sol.end(), k) - sol.begin();
                sol[idx] = min(sol[idx], pairs[i][1]);
            }
        }
        return sol.size();
    }
};