class Solution {
    public:
    void generate(int ind,int n,vector<int> &ds, vector<vector<int>> &ans,vector<int> &nums)
    {
       ans.push_back(ds);
        for(int i=ind;i<n;i++)
        {
            if(i>ind&&nums[i]==nums[i-1])continue;
            ds.push_back(nums[i]);
            generate(i+1,n,ds,ans,nums);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        generate(0,n,ds,ans,nums);
        return ans;
    }
};