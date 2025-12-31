class Solution {
    bool check(int r, int c, vector<vector<int>>& grid) {
        vector<int> cnt(10, 0);
        
        // Check numbers are 1 to 9 and distinct
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = grid[i][j];
                if (x < 1 || x > 9 || cnt[x]++)
                    return false;
            }
        }

        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];

        // Rows
        for (int i = 0; i < 3; i++) {
            if (grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum)
                return false;
        }

        // Columns
        for (int j = 0; j < 3; j++) {
            if (grid[r][c+j] + grid[r+1][c+j] + grid[r+2][c+j] != sum)
                return false;
        }

        // Diagonals
        if (grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum)
            return false;

        if (grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2] != sum)
            return false;

        return true;
    }

public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (check(i, j, grid))
                    ans++;
            }
        }
        return ans;
    }
};
