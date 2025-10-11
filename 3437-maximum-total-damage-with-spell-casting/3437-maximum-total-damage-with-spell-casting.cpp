class Solution {
    long long recursion(int i, vector<int>& vals, unordered_map<int,long long>& total, vector<long long>& dp) {
        if (i >= vals.size()) return 0;           
        if (dp[i] != -1) return dp[i];           

 
        long long skip = recursion(i + 1, vals, total, dp);

        long long take = total[vals[i]];
        int j = i + 1;
        while (j < vals.size() && vals[j] <= vals[i] + 2) j++;

        take += recursion(j, vals, total, dp);

        return dp[i] = max(skip, take);
    }

public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> total;
        for (int p : power) total[p] += p;

        vector<int> vals;
        for (auto &it : total) vals.push_back(it.first);
        sort(vals.begin(), vals.end());

        vector<long long> dp(vals.size(), -1);

        return recursion(0, vals, total, dp);
    }
};
