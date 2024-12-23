class Solution {
    public:
    void generate(int ind,int n,int target,vector<int> &ds,vector<vector<int>>&ans,vector<int> &candidates)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++)
        {
            if(i>ind&&candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            generate(i+1,n,target-candidates[i],ds,ans,candidates);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        int n = candidates.size();
        generate(0,n,target,ds,ans,candidates);
        return ans;
    }
};