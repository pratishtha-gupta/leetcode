class Solution {
    public:
    void generate(int ind,int n,vector<int> &ds, vector<vector<int>> &ans,vector<int> &nums)
    {
        if(ind==n)
        {
            auto it = find(ans.begin(),ans.end(),ds);
            if(it==ans.end())
            {
                ans.push_back(ds);
            }
            return;
        }
        //pick
        ds.push_back(nums[ind]);
        generate(ind+1,n,ds,ans,nums);
        ds.pop_back();
        //not pick
        generate(ind+1,n,ds,ans,nums);
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