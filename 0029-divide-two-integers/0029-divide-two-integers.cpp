class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle the edge case directly
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;  // Prevent overflow

        if (dividend == divisor)
            return 1;

        bool pos = (dividend >= 0) == (divisor >= 0);  // Check sign

        // Use long long to handle INT_MIN safely
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;

        while (a >= b) {
            int q = 0;
            while (a >= (b << (q + 1)) && (b << (q + 1)) > 0) {
                q++;
            }
            ans += (1LL << q);    // Use 1LL to avoid overflow
            a -= (b << q);
        }

        ans = pos ? ans : -ans;

        // Clamp the result to INT_MAX or INT_MIN if needed
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return ans;
    }
};
