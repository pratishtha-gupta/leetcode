class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int i,ans =nums[0],sum=nums[0];
        for(i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                sum+=nums[i];
                ans = max(ans,sum);
            }
            else
            {
                sum=nums[i];
            }
        }
        return ans;
    }
};