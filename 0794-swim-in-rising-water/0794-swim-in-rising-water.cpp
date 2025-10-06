class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
    vector<vector<int>> time(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
    pq.push({grid[0][0], {0,0}});
    time[0][0] = grid[0][0];

    int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};

    while(!pq.empty()) {
        auto [t, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;
        if(x == n-1 && y == n-1) return t;
        for(int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                int newTime = max(t, grid[nx][ny]);
                if(newTime < time[nx][ny]) {
                    time[nx][ny] = newTime;
                    pq.push({newTime, {nx, ny}});
                }
            }
        }
    }
    return -1;
    }
};