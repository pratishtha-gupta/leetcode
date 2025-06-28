class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i < nums.size(); i++) {
            v.push_back({nums[i], i});  
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        v.resize(k);
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });
        vector<int> res;
        for (auto it : v) {
            res.push_back(it.first);
        }

        return res;
    }
};
