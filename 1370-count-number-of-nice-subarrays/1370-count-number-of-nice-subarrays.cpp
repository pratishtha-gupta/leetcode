class Solution {
int func(vector<int> &nums,int k)
{
     int l=0,r=0,cnt=0,ones=0;
        while(r<nums.size())
        {
            if(k<0)
            return 0;
            if(nums[r]==1)
            ones++;
            while(ones>k)
            {
                if(nums[l]==1)
                ones--;
                l++;
            }
            cnt+=(r-l+1);
            r++;
        }
        return cnt;
}
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            nums[i]= nums[i]%2;
        }
        int ans = func(nums,k)-func(nums,k-1);
        return ans;
    }
};