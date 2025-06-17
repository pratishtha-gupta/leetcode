class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, right =0, maxi = 0, freq=0;
        while(right<nums.size())
        {
            if(nums[right]==1)
            {
                freq++;
                
            }
            else
            {
                 maxi = max(maxi,freq);
                freq=0;
               
                left++;
            }
            right++;
        }
        maxi = max(maxi,freq);
        return maxi;
    }
};