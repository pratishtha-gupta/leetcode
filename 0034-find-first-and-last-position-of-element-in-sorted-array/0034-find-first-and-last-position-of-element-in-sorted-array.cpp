class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, n = nums.size(),last=n;
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] >= target) {
                first = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if (first == -1 || nums[first] != target) {
            return {-1, -1}; 
        }

        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > target) {
                last = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
             last -= 1; 
        if (last < 0 || last >= n || nums[last] != target) {
            last = first; 
        }

        return {first, last};
    }
};
