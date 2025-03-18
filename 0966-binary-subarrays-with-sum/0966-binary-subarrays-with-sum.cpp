class Solution {
    int func(vector<int> &nums,int goal)
    {
        int cnt = 0,l=0,r=0,sum=0;
        while(r<nums.size())
        {
            if (goal<0)
            return 0;
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            cnt+= (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans = func(nums,goal)-func(nums,goal-1);
        return ans;
    }
};