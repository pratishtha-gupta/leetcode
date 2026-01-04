class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for (int x : nums) {
            bool found = false;

            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) {
                    int p = i;
                    int q = x / i;
                    if (p != q && isPrime(p) && isPrime(q)) {
                        ans += (1 + p + q + x);
                        found = true;
                    }
                    break;
                }
            }

            if (found) continue;

            int c = round(pow(x, 1.0 / 3));
            if (1LL * c * c * c == x && isPrime(c)) {
                ans += (1 + c + c * c + x);
            }
        }

        return ans;
    }
};
