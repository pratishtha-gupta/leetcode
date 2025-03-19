class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count =0;
        for(int i=2;i<nums.size();i++)
        {
            if(nums[i-2]==0)
            {
                count++;
                nums[i-2]=1;
                if(nums[i-1]==0) nums[i-1]=1;
                else nums[i-1]=0;
                if(nums[i]==0) nums[i]=1;
                else nums[i]=0;
            }
        }
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum==nums.size())
        return count;
        else
        return -1;
    }
};