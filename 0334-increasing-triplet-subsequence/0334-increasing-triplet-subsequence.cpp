class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1{2147483647};
        int min2{2147483647};
        for (auto num : nums) {
            if (num <= min1) {
                min1 = num;
            }
            else if (num <= min2) {
                min2 = num;
            }
            else return true;
        }
        return false;
    }
};