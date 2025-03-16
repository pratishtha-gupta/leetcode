class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> index_map = buildMap(nums, n);
        vector<int> res;

        for (int q : queries) {
            res.push_back(solve(index_map[nums[q]], q, n));
        }
        return res;
    }

private:
    unordered_map<int, vector<int>> buildMap(vector<int>& nums, int n) {
        unordered_map<int, vector<int>> index_map;
        for (int i = 0; i < n; i++) {
            index_map[nums[i]].push_back(i);
        }
        return index_map;
    }

    int solve(vector<int>& positions, int q, int n) {
        if (positions.size() < 2) return -1;

        int pos = binarySearch(positions, q);
        
        // Left and right neighbors in sorted list
        int left = (pos == 0) ? positions.back() : positions[pos - 1];
        int right = (pos == positions.size() - 1) ? positions.front() : positions[pos + 1];

        return min(dist(q, left, n), dist(q, right, n));
    }

    int binarySearch(vector<int>& positions, int target) {
        int left = 0, right = positions.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (positions[mid] == target) return mid;
            else if (positions[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

    int dist(int i, int j, int n) {
        int d = abs(i - j);
        return min(d, n - d);
    }
};
