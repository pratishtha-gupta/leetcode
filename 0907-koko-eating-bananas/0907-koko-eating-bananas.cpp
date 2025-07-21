class Solution {
    bool check(int mid, vector<int> &piles, int h) {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + mid - 1LL) / mid;  // Ceiling division
            if (time > h) return false;
        }
        return time <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1000000000;
        int ans = high;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, piles, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
