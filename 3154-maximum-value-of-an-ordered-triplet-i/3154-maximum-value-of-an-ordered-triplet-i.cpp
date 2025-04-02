class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long i,j,k,n=nums.size(),ans=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                for(k=j+1;k<n;k++)
                {
                    long long val = ((long long)nums[i]-nums[j])*(nums[k]);
                    ans = max(ans,val);
                }
            }
        }
        if(ans>0) return ans;
        return 0;
    }
};