class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> m;
        int n = s.size();
        for (int i{}; i <= n - 10; i ++) {
            string sub{s.substr(i, 10)};
            if (m[sub] == 1) {
                res.push_back(sub);
            }
            m[sub] ++;
        }
        return res;
    }
};