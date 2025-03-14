class Solution {
    bool check(vector<int>& candies, long long k,long long mid)
    {
        long long i,st=0;
        for(i=0;i<candies.size();i++)
        {
            if(candies[i]>=mid)
            {
                st+=candies[i]/mid;
            }
        }
        if(st>=k)
        return true;
        else
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left=1,right = INT_MAX,ans=0;
        while(left<=right)
        {
            long long mid = left+(right-left)/2;
            if(check(candies,k,mid))
            {
                ans = mid;
                left = mid+1;
            }
            else right = mid-1;
        }
        return ans;
    }
};