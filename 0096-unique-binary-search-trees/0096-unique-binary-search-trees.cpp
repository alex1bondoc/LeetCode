class Solution {
public:
    int numTrees(int n) {
        auto back = [&](auto self, int i) {
            if (i <= 1) return 1;
            int res{};
            for (int j{}; j < i; ++j) {
                res += self(self, j) * self(self, i - 1 - j);
            }
            return res;
            
        };
        return back(back, n);
    }
};