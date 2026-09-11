class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n), post(n);
        pre[0] = 0;
        post[n - 1] = 0;
        for (int i{1}; i < n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
            post[n - i - 1] = post[n - i] + nums[n - i];
        }
        for (int i{}; i < n; ++i) {
            if (pre[i] == post[i]) return i;
        }
        return -1;
    } 
};