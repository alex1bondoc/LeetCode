class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& sol) {
        vector<int> res;
        int l{}, r{static_cast<int>(sol[0].size() - 1)};
        int b{}, t{static_cast<int>(sol.size() - 1)};
        while (l <= r && b <= t) {
            for (int i{l}; i <= r; ++i) {
                res.push_back(sol[b][i]);
            }
            b ++;
            for (int i{b}; i <= t; ++i) {
                res.push_back(sol[i][r]);
            }
            r --;
            if (b <= t)
            for (int i{r}; i >= l; --i) {
                res.push_back(sol[t][i]);
            }
            t --;
            if (l <= r)
            for (int i{t}; i >= b; --i) {
                res.push_back(sol[i][l]);
            }
            l ++;
        } 


        return res;
    }
};