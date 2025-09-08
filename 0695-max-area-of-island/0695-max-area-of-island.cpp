class Solution {
    int dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == 0) {
            return 0;
        }

        vis[i][j] = 1;
        int area = 1; // count current cell

        int delrow[4] = {1, 0, -1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for(int a = 0; a < 4; a++) {
            int row = i + delrow[a];
            int col = j + delcol[a];
            area += dfs(row, col, n, m, vis, grid);
        }
        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    ans = max(ans, dfs(i, j, n, m, vis, grid));
                }
            }
        }
        return ans;
    }
};
