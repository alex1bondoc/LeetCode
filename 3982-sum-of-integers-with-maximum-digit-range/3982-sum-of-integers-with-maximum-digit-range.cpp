class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int sum{};
        int maxi{};

        for (const auto& num : nums) {
            int cnum{num};
            int mx{}, mi{10};
            while (cnum) {
                mx = std::max(mx, cnum%10);
                mi = std::min(mi, cnum%10);
                cnum /= 10;
            }
            if (mx - mi > maxi) {
                maxi = mx - mi;
                sum = num;
            }
            else if (mx - mi == maxi) {
                sum += num;
            }
        }
        return sum;
    }
};