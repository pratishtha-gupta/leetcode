class Solution {
    bool isvalid(long long mid, vector<int>& ranks, long long cars) {
        long long sum = 0;
        for (long long i = 0; i < ranks.size(); i++) {
            sum += sqrt(mid / ranks[i]);  // Directly using sqrt
            if (sum >= cars) return true; // Early exit to prevent overflow
        }
        return sum >= cars;
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0, right = 1e14, ans = 0; // Safe upper bound
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (isvalid(mid, ranks, cars)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
