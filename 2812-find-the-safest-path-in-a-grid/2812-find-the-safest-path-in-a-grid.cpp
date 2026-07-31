class Solution {
    bool canReach(int safe, vector<vector<int>> &dist) {
        int n = dist.size();

        if (dist[0][0] < safe) return false;

        vector<vector<int>> vis(n, vector<int>(n, 0));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = 1;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return true;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (vis[nx][ny])
                    continue;

                if (dist[nx][ny] < safe)
                    continue;

                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        int lo = 0;
        int hi = 2 * (n - 1);

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (canReach(mid, dist))
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return hi;
    }
};