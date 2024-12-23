class Solution {
    public:
    void generate (int ind,int n, vector <int>&nums,vector<int> &ds,vector<vector<int>> &arr)
    {
        if(ind==n)
        {
            arr.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
         generate(ind+1,n,nums,ds,arr);
        ds.pop_back();
        generate(ind+1,n,nums,ds,arr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> arr;
        vector<int> ds;
        int n = nums.size();
        generate(0,n,nums,ds,arr);
        return arr;
    }
};