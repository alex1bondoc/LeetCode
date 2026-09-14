class Solution {
public:
    int calculate(string s) {
        std:: stack<pair<int, int>> st;
        long long res = 0;
        int sign = 1;
        int n = s.size();
        for (int i{}; i < n; ++i) {
            char c = s[i];
            if (c == ' ') continue;
            if (c >= '0' && c <= '9') {
                long long number = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {

                    number = number * 10 + (s[i] - '0');
                    i ++;
                }
                cout << number;
                res += number * sign;
                i --;
            }
            else if (c == '+') {
                sign = 1;
            }
            else if (c == '-') {
                sign = -1;
            }
            else if (c == '('){
                st.push({res, sign});
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                auto [r, s] = st.top();
                st.pop();
                sign = s;
                res = r + sign * res;
            }

        }
        return res;
    }
};