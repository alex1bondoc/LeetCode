class Solution {
public:
    string decodeString(string s) {
        std::stack<pair<int, string>> st;
        st.push({0, ""});
        int n{static_cast<int>(s.size())};
        for (int i{}; i < n; ++i) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                int num = 0;
                int ind = i;
                while (s[ind] != '[') {
                    num = num * 10 + (s[ind] - '0');
                    ind ++;
                }
                i = ind;
                st.push({num, ""});
            }
            else if (c >= 'a'&& c <= 'z') {
                st.top().second += c;

            }
            else if (c == ']') {
                const auto [cnt, str] = st.top();
                st.pop();
                for (int j{}; j < cnt && st.size(); ++j) {
                    st.top().second += str;
                }
            }
        }
        return st.top().second;
    }
};