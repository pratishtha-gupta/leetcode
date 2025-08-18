class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int k = mp.size();
        int l=0,r=0,cnt=0;
        mp.clear();
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp.size()==k)
            {
               cnt+=(n-r);
               mp[nums[l]]--;
               if(mp[nums[l]]==0) mp.erase(nums[l]);
               l++;
            }
            r++;
        }
        return cnt;
        
    }
};