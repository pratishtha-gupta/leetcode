class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0, presum = 0;
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            presum += nums[i];
            int diff = presum-k;
            cnt+= mp[diff];
            mp[presum]+=1;
        }
        return cnt;
    }
};