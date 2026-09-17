// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int first = 1, last = n;
        int ans = 0;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                last = mid - 1;
            }
            else {
                first = mid + 1;
            }
        }
        return ans;
    }
};