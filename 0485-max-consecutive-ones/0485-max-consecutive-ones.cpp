class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len=0,ans=0;
        nums.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                len++;
            }
            else
            {
                ans = max(ans,len);
                len=0;
            }
        }
        return ans;
    }
};