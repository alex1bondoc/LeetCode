class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ls{}, rs = s.size() - 1;
        int lt{}, rt = t.size() - 1;
        while (lt <= rt) {
            while (lt <= rt && t[lt] != s[ls]) {
                lt ++;
            } 
            while (lt <= rt && t[rt] != s[rs]) {
                rt--;
            }
            if (lt <= rt) {
                if (ls != rs && lt == rt) return false;
                ls++, lt++;
                rs--, rt--;
                if (ls > rs) return true;
            }
            
        }
        return ls > rs;
    }
};