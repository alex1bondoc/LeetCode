class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& I) {
        const int n=I.size();
        sort(I.begin(), I.end());
        long long cnt=0;
        for(int i=0; i<n; i++){
            int b=I[i][1];
            int j=upper_bound(I.begin()+i+1, I.end(), b, 
            []( int val, const vector<int>& seg){
                return val<seg[0];
            })-I.begin();
            cnt+=j-i-1;
        }
        return cnt;
    }
};