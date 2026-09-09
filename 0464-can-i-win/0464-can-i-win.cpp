class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;

        vector<int> memo(1 << maxChoosableInteger, -1);
        auto back = [&](auto self, int mask, int total) -> bool {
            if (memo[mask] != -1) return memo[mask];
            for (int i{1}; i <= maxChoosableInteger; ++i) {
                int bit = 1 << (i - 1);
                if (mask & bit) continue;
                if (total + i >= desiredTotal || !self(self, mask | bit, total + i))
                    return memo[mask] = true;
            }
            return memo[mask] = false;
        };
        return back(back, 0, 0);
    }
};