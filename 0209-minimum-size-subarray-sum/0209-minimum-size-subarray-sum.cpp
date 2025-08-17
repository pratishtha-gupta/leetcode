class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,sum=0;
        int ans =INT_MAX;
        int n = nums.size();
        while(r<n)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                ans = min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
            
            r++;
        }
        if(ans==INT_MAX) return 0;
        else return ans;
    }
};