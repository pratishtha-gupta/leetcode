class Solution {
    bool check(int mid, vector<int>& nums, int k) {
        int sum = 0, ct = 1; 
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mid) return false;
            if (sum + nums[i] > mid) {
                ct++;
                sum = nums[i]; 
            } else {
                sum += nums[i];
            }
        }
        return ct <= k; 
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid, nums, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
