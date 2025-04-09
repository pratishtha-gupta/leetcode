class Solution {
    int func(int ind,vector<int>&dp,vector<int>& nums)
    {
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = nums[ind]+ func(ind-2,dp,nums);
        int notpick = 0+ func(ind-1,dp,nums);
        return dp[ind] = max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2=0,prev = nums[0];
        for(int i=1;i<n;i++)
        {
            int pick = nums[i]+prev2;
            int notpick = 0+prev;
            int cur = max(pick,notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
};