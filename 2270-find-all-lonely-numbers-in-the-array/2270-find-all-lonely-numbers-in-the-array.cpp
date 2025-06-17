class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        if(nums.size()==1)
        {
            ans.push_back(nums[0]);
            return ans;
        }
        if(nums[1]-nums[0]>=2) ans.push_back(nums[0]);
        
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]-nums[i-1]>=2&&nums[i+1]-nums[i]>=2)
            ans.push_back(nums[i]);
        }
        int n = nums.size();
        if(nums[n-1]-nums[n-2]>=2) ans.push_back(nums[n-1]);
        return ans;
    }
};