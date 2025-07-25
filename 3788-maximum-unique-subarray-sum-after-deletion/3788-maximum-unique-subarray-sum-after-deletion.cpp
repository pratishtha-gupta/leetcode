class Solution {
public:
    int maxSum(vector<int>& nums) {
        set <int> num;
        int nega = INT_MIN;
        bool pos=0;
        for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>0)
                num.insert(nums[i]) ;
                else
                nega=max(nega,nums[i]);
                if(nums[i]>=0)
                    pos=1;
            }
        int sum=0;
        if(!pos)
            return nega;
        for(auto x:num)
            {
                sum+=x;
            }
        return sum;
    }
};