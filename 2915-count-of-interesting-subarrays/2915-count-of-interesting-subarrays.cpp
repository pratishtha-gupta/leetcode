class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res = 0;
        int prefix = 0;
        unordered_map<int, long long> freq;
        freq[0] = 1;  

        for (int num : nums) {
            if (num % modulo == k) {
                prefix++;
            }

            int target = (prefix - k + modulo) % modulo;
            if (freq.count(target)) {
                res += freq[target];
            }

            freq[prefix % modulo]++;
        }

        return res;
     
    }
};