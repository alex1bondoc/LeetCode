class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        map<vector<int>, int> mp;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[i + 1]);
                sort(v.begin(), v.end());
                mp[v]++;
            }else{
                l++;
            }
        }
        int mxfrq = 0;
        for (auto& p : mp) {
            mxfrq = max(mxfrq, p.second);
        }

        return l + mxfrq;
        
    }
};