class Solution {
    bool check(int mid,vector<int>&weights,int days)
    {
        int ct = 0,maxi = mid,sum=0;
        for(int i=0;i<weights.size();i++)
        {
            if (weights[i] > mid) return false;
            sum+=weights[i];
            if(sum>maxi)
            {
                ct++;
                sum=weights[i];
            }    
        }
        ct++;
         return ct<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 1,high =1e9;
        int ans = high;
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            if(check(mid,weights,days))
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