class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt{1};
        if (n == 0) return true;
        for (int i{}; i < flowerbed.size(); ++i) {
            int prev = (i == 0) ? 0 : flowerbed[i - 1];
            int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];
            if (prev == 0 && next == 0 && flowerbed[i] == 0) {
                n--;
                flowerbed[i] = 1;
                if (n == 0) return true;
            } 
            cout << prev << " " << next << endl;
        }
        return false;
    }
};