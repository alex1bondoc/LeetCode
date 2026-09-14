class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int g = 0;
        int total = 0;
        for (int i{}; i < gas.size(); ++i) {
            g += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (g < 0) {
                res = i + 1;
                g = 0;
            }
        }
        return total < 0 ? -1 : res;
    }
};