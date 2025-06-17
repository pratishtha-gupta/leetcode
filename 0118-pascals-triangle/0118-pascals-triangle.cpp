class Solution {
    vector<int> generates(int rows)
    {
        vector<int> v;
        long long ans =1;
        v.push_back(1);
        for(int i=1;i<rows;i++)
        {
            ans = ans*(rows-i);
            ans = ans/i;
            v.push_back(ans);
        }
        return v;
    }
public:
    vector<vector<int>> generate(int rows) {
        vector<vector<int>> ans;
        for(int i=1;i<=rows;i++)
        {
            ans.push_back(generates(i));
        }
        return ans;
    }
};