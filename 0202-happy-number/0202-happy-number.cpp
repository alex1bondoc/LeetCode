class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1) {
            if (s.contains(n)) return false;
            s.insert(n);
            int sum{};
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;

        }
        return true;
    }
};