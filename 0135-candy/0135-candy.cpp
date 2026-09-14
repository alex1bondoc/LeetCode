class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candy = n;
        for (int i{}; i < n; ++i) {
            if (ratings[i] == ratings[i + 1]) i++;
            int peak = 0;
            while (i < n - 1 && ratings[i] > ratings[i + 1]) {
                peak ++;
                candy += peak;
                i ++;
            }
            int valey = 0;
            while (ratings[i] < ratings[i + 1]) {
                valey ++;
                candy += valey;
                i++;
            }
        }


        return candy;

    }
};