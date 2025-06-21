class Solution {
    bool check(int mid , vector<int> &nums, int threshold)
    {
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            int curr;
            if(nums[i]%mid==0) curr = nums[i]/mid;
            else curr = nums[i]/mid +1;
            sum+= curr;
        }
        return (sum<=threshold);
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low =1 , high = *max_element(nums.begin(),nums.end());
        int ans = high;
        //ffffttttttt
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,nums,threshold))
            {
                ans = mid;
                high = mid-1;
            }
            else
            low = mid+1;
        }
        return ans;
    }
};