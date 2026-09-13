class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        std::stack<pair<int, int>> st;
        for (int i{}; i <n; ++i) {
            auto& temp = temperatures[i];
            while (st.size() && st.top().second < temp) {
                auto& [index, t] = st.top();
                st.pop();
                res[index] = i - index;
            }
            st.push({i, temp});
        }
        return res;
    }
};