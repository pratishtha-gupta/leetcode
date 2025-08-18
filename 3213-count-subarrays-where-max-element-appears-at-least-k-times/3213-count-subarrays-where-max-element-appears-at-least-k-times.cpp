class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n= nums.size();
        int val = *max_element(nums.begin(),nums.end());
        int left=0,right=0,cnt=0;
        long long ans =0;
        while(right<n)
        {
            if(nums[right]==val) cnt++;
            while(cnt>=k)
            {
                ans+=(n-right);
                if(nums[left]==val)
                {
                    cnt--;
                }
                left++;
            }
            right++;
        }
        return ans;
    }
};