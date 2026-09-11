class Solution {
public:
    string removeStars(string s) {
        string res{};
        for (char c : s) {
            if (c != '*') res += c;
            else if (res.size()){
                res.pop_back();
            }
        }
        return res;
    }
};