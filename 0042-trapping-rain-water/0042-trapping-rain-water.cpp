class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        vector<int> presum(n,0);
        vector<int> suffixsum(n,0);
        presum[0] = heights[0];
        for(int i=1;i<n;i++)
        {
            presum[i] = max(presum[i-1],heights[i]);
        }
        suffixsum[n-1]= heights[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixsum[i]= max(heights[i],suffixsum[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int trap = min(presum[i],suffixsum[i])-heights[i];
            ans+=trap;
        }
        return ans;

        
    }
};