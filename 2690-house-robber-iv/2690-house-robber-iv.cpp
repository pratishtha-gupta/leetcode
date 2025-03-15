
class Solution {
    bool isvalid(int mid,vector<int>&nums,int k)
    {
        int ct=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mid>=nums[i])
            {
                ct++;
                i++;
            }
        }
        if(ct>=k)
        return true;
        else
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int start = 0,end = INT_MAX, ans = 0;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(isvalid(mid,nums,k))
            {
                ans = mid;
                end = mid-1;
            }
            else
            start = mid+1; 
        }
        return ans;
    }
};