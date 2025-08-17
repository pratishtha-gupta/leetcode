class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map <int,int> mp;
        for(auto it: nums)
        {
            mp[it]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),[](auto &a, auto &b){return b.second<a.second;});
        for(auto it:v)
        {
            if(k>0)
            {
                res.push_back(it.first);
                k--;
            }
        }
        return res;
        
    }
};