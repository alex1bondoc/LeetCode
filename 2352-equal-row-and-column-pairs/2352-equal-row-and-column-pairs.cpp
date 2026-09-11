class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int res{};
        map<vector<int>, int> s{};
        for (int i{}; i < grid.size(); ++i) {
            s[grid[i]] ++;
        } 
        for (int i{}; i <grid[0].size(); ++i) {
            vector<int> v;
            for (int j{}; j < grid.size(); ++j) {
                v.push_back(grid[j][i]);
            }
            if (s.contains(v)) res += s[v];
        }
        return res;
    }
};