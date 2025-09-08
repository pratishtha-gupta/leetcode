class Solution {
    void dfs(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<char>>& grid) {
      
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] == '0') 
            return;

        vis[i][j] = 1;

        int delrow[4] = {1, 0, -1, 0};
        int delcol[4] = {0, 1, 0, -1};

        for(int a = 0; a < 4; a++) {
            int row = i + delrow[a];
            int col = j + delcol[a];
            dfs(row, col, n, m, vis, grid);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    dfs(i, j, n, m, vis, grid);
                }
            }
        }
        return count;
    }
};
