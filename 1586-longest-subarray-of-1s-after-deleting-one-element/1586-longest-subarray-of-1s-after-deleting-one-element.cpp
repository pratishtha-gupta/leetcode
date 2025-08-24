class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0,right=0, n = nums.size();
        int ans =0,zeroes=0;
        while(right<n)
        {
            if(nums[right]==0)
            zeroes++;
            while(zeroes>1)
            {
                if(nums[left]==0){
                    zeroes--;
                }
                left++;
            }
            int len = right-left+1;
            ans = max(ans,len);
            right++;
        }
        return ans-1;
    }
};