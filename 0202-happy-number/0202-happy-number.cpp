class Solution {
public:
    int sq(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n, fast = n;
        while (true) {
            slow = sq(slow);
            fast = sq(sq(fast));
            if (slow == fast) break;
        }
        return slow == 1;
    }
};