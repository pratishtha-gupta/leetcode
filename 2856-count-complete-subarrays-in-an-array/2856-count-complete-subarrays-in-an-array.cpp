class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int distinct = totalSet.size();

        unordered_map<int, int> cnt;
        int left = 0, res = 0;

        for (int right = 0; right < n; ++right) {
            cnt[nums[right]]++;

            while (cnt.size() == distinct) {
                // All subarrays starting from left and ending from right to n-1 are complete
                res += n - right;

                // Shrink the window from the left
                cnt[nums[left]]--;
                if (cnt[nums[left]] == 0) {
                    cnt.erase(nums[left]);
                }
                left++;
            }
        }

        return res;
    }
};
