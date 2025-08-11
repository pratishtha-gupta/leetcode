class Solution {
    int func(vector<int>& nums, int k)
    {
        int ct=0,r=0,l=0;
        map<int,int> mp;
        while(r<nums.size())
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            ct+=(r-l+1);
            r++;
        }
        return ct;
    } 

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    } 
};
