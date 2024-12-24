class Solution {
public:
    void generate(int ind,int target,int k,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(ds.size()==k&&target==n)
        {
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<=9;i++)
        {
            if(target>n) break;
            //pick
            ds.push_back(i);
            generate(i+1,target+i,k,n,ds,ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(1,0,k,n,ds,ans);
        return ans;
    }
};