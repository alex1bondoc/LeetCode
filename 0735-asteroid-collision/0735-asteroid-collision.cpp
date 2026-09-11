class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for (auto as : asteroids) {
                bool add{true};

            while (res.size() && res.back() > 0 && as < 0) {
                if (res.back() > -as) {
                    add = false;
                    break;
                }
                else if( res.back() == -as) {
                    res.pop_back();
                    add = false;
                    break;
                }
                else {
                    res.pop_back();
                }
            }
            if (add)
                res.push_back(as);
        }
        return res;
    }
};