class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int i;
        int ans =1,cnt=1;
        for(i=0;i<n-1;i++)
        {
            if(nums[i+1]>nums[i])
            {
                cnt++;
            }
            else
            {
                ans = max(ans,cnt);
                cnt=1;
                continue;
            }
        }
        ans = max(ans,cnt);
        cnt =1;
         for(i=0;i<n-1;i++)
        {
            if(nums[i+1]<nums[i])
            {
                cnt++;
            }
            else
            {
                ans = max(ans,cnt);
                cnt=1;
                continue;
            }
        }
          ans = max(ans,cnt);
        return ans;
    }
};