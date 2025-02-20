class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(),low = 0,high = n-1;
        while(low<=high)
        {
            int mid = low+(high - low)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            if(nums[mid]==nums[low] && nums[high]==nums[mid])
            {
                low++;
                high--;
                continue;
            }
            //left sorted
            if(nums[low]<=nums[mid])
            {
                if(target>=nums[low] && target<=nums[mid])
                {
                    high = mid-1;
                }
                else
                low= mid+1;
            }
            //right sorted
            else
            {
                if(target>=nums[mid] && target<=nums[high])
                {
                    low = mid+1;
                }
                else
                high = mid-1;
            }
        }
        return false;
    }
};