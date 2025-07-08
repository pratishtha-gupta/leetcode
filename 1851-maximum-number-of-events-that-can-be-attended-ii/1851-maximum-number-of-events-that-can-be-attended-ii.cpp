class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return dfs(0, k, events);
    }

private:
    vector<vector<int>> dp;

    int dfs(int index, int count, vector<vector<int>>& events) {
        if (count == 0 || index == events.size()) return 0;
        if (dp[index][count] != -1) return dp[index][count];

        int nextIndex = upperBound(events, events[index][1]);
        int skip = dfs(index + 1, count, events);
        int take = events[index][2] + dfs(nextIndex, count - 1, events);

        return dp[index][count] = max(skip, take);
    }

    int upperBound(vector<vector<int>>& events, int targetEnd) {
        int low = 0, high = events.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (events[mid][0] <= targetEnd)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};
