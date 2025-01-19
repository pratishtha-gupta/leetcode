class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0,diff,mini=prices[0];
        for(int i=0;i<n;i++)
        {
            if(prices[i]<mini)
            {
                mini = prices[i];
            }
            else
            {
                diff = prices[i]-mini;
                ans = max(ans,diff);
            }
        }
        return ans;
    }
};