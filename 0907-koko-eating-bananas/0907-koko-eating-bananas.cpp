class Solution {
    bool check(int mid, vector<int> &piles, int h)
    {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + mid - 1ll) / mid; 
            if(time>h) return false;// ceiling of division
        }
        return time <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        
        while (low <= high)
        {
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
