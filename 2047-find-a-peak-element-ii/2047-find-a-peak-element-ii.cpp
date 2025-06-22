class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int n = mat.size();       // rows
        int m = mat[0].size();    // cols

        int low = 0, high = m - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            // Step 1: Find max in the mid column
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int left = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int right = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

            // Step 2: Compare with neighbors
            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right) {
                return {maxRow, mid};
            } else if (left > mat[maxRow][mid]) {
                high = mid - 1;  // move left
            } else {
                low = mid + 1;   // move right
            }
        }

        return {-1, -1};  // should never reach here
    }
};