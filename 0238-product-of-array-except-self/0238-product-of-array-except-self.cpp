class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 0), post(n, 0);
        for (int i{}; i < n; ++i) {
            if (i == 0) {
                pre[0] = 1;
                post[n - 1] = 1;
            }
            else {
                pre[i] = pre[i - 1] * nums[i - 1];
                post[n - i - 1] = post[n - i] * nums[n - i]; 
            }
        }
        vector<int> res;
        for (int i{}; i < n; ++i) {
            res.push_back(pre[i] * post[i]);
        }
        return res;
    }
};