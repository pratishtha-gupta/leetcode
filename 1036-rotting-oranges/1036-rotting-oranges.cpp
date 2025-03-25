
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int freshCount = 0;  
        int time = 0; 

   
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};


        while (!q.empty() && freshCount > 0) {
            int size = q.size();
            time++;  
            
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                for (auto dir : directions) {
                    int newRow = r + dir.first;
                    int newCol = c + dir.second;

                    if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
                        grid[newRow][newCol] == 1 && vis[newRow][newCol] == 0) {
                        
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = 2;
                        vis[newRow][newCol] = 1;
                        freshCount--; 
                    }
                }
            }
        }
        return (freshCount == 0) ? time : -1;
    }
};