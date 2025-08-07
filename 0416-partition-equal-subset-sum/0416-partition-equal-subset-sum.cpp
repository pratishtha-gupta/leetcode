class Solution {
public:
    bool subsetsum(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notpick = subsetsum(ind - 1, nums, target, dp);
        bool pick = false;
        if (nums[ind] <= target) {
            pick = subsetsum(ind - 1, nums, target - nums[ind], dp);
        }

        return dp[ind][target] = pick || notpick;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int it : nums)
            sum += it;

        if (sum & 1)
            return false;

        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return subsetsum(n - 1, nums, target, dp);
    }
};
