class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int res{};
        for (int num : nums) {
            if (mp.contains(k - num)) {
                mp[k - num]--;
                if (mp[k-num] == 0) mp.erase(k - num);
                res++;
            }
            else {
                mp[num]++;
            }
        }
        return res;
    }
};