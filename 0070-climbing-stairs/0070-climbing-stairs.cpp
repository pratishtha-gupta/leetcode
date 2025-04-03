class Solution {
    int dp[1000];
    int calculate (int n)
    {
        if(n==0||n==1) return 1;
        if(dp[n]!=0) return dp[n];
        return dp[n] = calculate(n-1)+calculate(n-2);
    }
public:
    int climbStairs(int n) {
        int ans = calculate (n);
        return ans;
    }
};