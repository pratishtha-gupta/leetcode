class Solution {
    public:
void findcombinationsum(int ind, int target, vector<int>& candidates,
                     vector<vector<int>>& ans, vector<int>& ds) {
    if (ind == candidates.size()) {
        if (target == 0) {
            ans.push_back(ds);
        }
        return;
    }
    // pick up the element
    if (candidates[ind] <= target) {
        ds.push_back(candidates[ind]);
        findcombinationsum(ind, target - candidates[ind], candidates, ans, ds);
        ds.pop_back();
    }
    findcombinationsum(ind + 1, target, candidates, ans, ds);
}
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findcombinationsum(0, target, candidates, ans, ds);
        return ans;
    }
};

