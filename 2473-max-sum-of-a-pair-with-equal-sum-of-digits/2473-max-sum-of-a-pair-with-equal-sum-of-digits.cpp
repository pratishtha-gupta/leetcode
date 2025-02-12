class Solution {
    private: 
    int sum(int n)
    {
        int a=n;
        int ans=0;
        while(a>0)
        {
           int dig = a%10;
           ans+=dig;
           a=a/10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        vector <pair<int,int>> v;
        for(auto it: nums)
        {
            int digi= sum(it);
            v.push_back({digi,it});
        }
        sort(v.begin(),v.end());
        int ans = -1;
        for(int i=1;i<v.size();i++)
        {
            int current= v[i].first;
            int prev = v[i-1].first;
            if(current==prev)
            {
                int sumi= v[i].second+v[i-1].second;
                 ans = max(ans,sumi);
            }
        }
        return ans;
    }
};