class Solution {
    int func (vector<int> &v)
    {
        int n = v.size();
        int prev2=0,prev = v[0];
        for(int i=1;i<n;i++)
        {
            int pick = v[i]+prev2;
            int notpick = 0+prev;
            int cur = max(pick,notpick);
            prev2 = prev;
            prev = cur;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> temp1,temp2;
        temp1= nums;
        temp1.pop_back();
        for(int i=1;i<nums.size();i++)
        {
            temp2.push_back(nums[i]);
        }
        return max(func(temp1),func(temp2));
    }
};