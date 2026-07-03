class Solution {
public:
    int passwordStrength(string password) {
        int strength{};
        unordered_set<char> s;
        for (char c : password) {
            if (s.find(c) != s.end()) continue;
            if (c >= 'a' && c <= 'z') strength ++;
            else if (c >= 'A' && c <= 'Z') strength += 2;
            else if (c >= '0' && c <= '9') strength += 3;
            else strength += 5;
            s.insert(c);
        }
        return strength;
    }
};