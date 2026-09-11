class Solution {
public:
    string reverseVowels(string s) {
        int l{}, r = s.size() - 1;
        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
            else if (isVowel(s[l])) {
                r --;
            }
            else if (isVowel(s[r])) {
                l ++;
            }
            else {
                l ++;
                r --;
            }
        }
        return s;
    }
private: 
    bool isVowel(char c) {
        return tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u';
    }
};