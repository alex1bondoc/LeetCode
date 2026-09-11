class Solution {
public:
    int compress(vector<char>& ch) {
        int n = ch.size();
        if(n==1) return 1;
        vector<char> ans;
        for(int i = 0; i < n; i++){
            int consec = 1; // count consecutive chars "bb" -> consec == 2
            for(int j=i+1; j < n; j++){
                if(ch[j]==ch[i]) consec++;
                else break;
            }
            if(consec > 1){
                ans.push_back(ch[i]);
                string sNum = to_string(consec);
                for(char c : sNum) ans.push_back(c);
                i += (consec-1);
            }
            else ans.push_back(ch[i]);
        }
        ch.clear(); // we have to modify input array that is given
        for(char c : ans) ch.push_back(c);
        return ans.size();
    }
};