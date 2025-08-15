class Solution {
    bool find(int ind, vector<int>& nums, vector<int>& dp) {
        if (ind >= nums.size() - 1) return true;  // Reached or passed last index
        if (dp[ind] != -1) return dp[ind];        // Memoization

        int maxJump = nums[ind];
        for (int i = 1; i <= maxJump; i++) {
            if (find(ind + i, nums, dp)) 
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }

public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return find(0, nums, dp);
    }
};
