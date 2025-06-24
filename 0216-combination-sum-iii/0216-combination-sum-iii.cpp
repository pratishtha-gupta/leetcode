class Solution {
    void generate(vector<vector<int>> &ans, int k, int n, vector<int> &ds, int sum, int ind) {
        if (ds.size() == k) {
            if (sum == n) ans.push_back(ds);
            return;
        }
        
        for (int i = ind; i <= 9; i++) {
            if (sum + i > n) break; 
            ds.push_back(i);         
            generate(ans, k, n, ds, sum + i, i + 1); 
            ds.pop_back();             
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        generate(ans, k, n, ds, 0, 1); 
        return ans;
    }
};
