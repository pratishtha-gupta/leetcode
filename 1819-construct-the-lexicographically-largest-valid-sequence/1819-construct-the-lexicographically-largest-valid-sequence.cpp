class Solution {
public:
    bool backtrack(vector<int> &res, vector<bool> &used, int n, int index) {
        if (index == res.size()) return true; // Successfully filled all positions
        
        if (res[index] != 0) return backtrack(res, used, n, index + 1); // Skip filled positions

        for (int num = n; num >= 1; --num) { // Try placing numbers from n to 1 (largest first)
            if (used[num]) continue; // Skip already placed numbers

            if (num == 1) { // Place '1' only once
                res[index] = 1;
                used[1] = true;
                if (backtrack(res, used, n, index + 1)) return true;
                res[index] = 0; // Backtrack
                used[1] = false;
            } else { // Place numbers ≥ 2 (which appear twice with spacing of num)
                if (index + num < res.size() && res[index + num] == 0) {
                    res[index] = res[index + num] = num;
                    used[num] = true;
                    if (backtrack(res, used, n, index + 1)) return true;
                    // Backtrack
                    res[index] = res[index + num] = 0;
                    used[num] = false;
                }
            }
        }
        return false; // No valid placement found
    }

    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> res(size, 0);
        vector<bool> used(n + 1, false); // Track used numbers
        backtrack(res, used, n, 0);
        return res;
    }
};
