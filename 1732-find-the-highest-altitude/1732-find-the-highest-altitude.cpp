class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res{};
        int al{};
        for (int g : gain) {
            al += g;
            res = max(res, al);
        }
        return res;
    }
};