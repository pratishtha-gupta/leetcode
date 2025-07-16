class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }

        if(target>sum || (sum-target)%2!=0){
            return 0;
        }

         int newTarget = (sum - target) / 2;


        vector<int>dp(newTarget+1,0);
        dp[0]=1;


        for(int i=0;i<nums.size();i++){
            for(int j=newTarget;j>=nums[i];j--){
                dp[j]+=dp[j-nums[i]];
            }
        }

return dp[newTarget];
    }
};