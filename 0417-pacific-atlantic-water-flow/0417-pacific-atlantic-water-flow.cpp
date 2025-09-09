class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        queue<pair<int,int>> qp, qa;
        
        for(int i=0; i<n; i++) {
            qp.push({i,0});
            qa.push({i,m-1});
            pac[i][0] = 1;
            atl[i][m-1] = 1;
        }
        for(int j=0; j<m; j++) {
            qp.push({0,j});
            qa.push({n-1,j});
            pac[0][j] = 1;
            atl[n-1][j] = 1;
        }

        auto bfs = [&](queue<pair<int,int>>& q, vector<vector<int>>& vis) {
            int dr[4] = {1,-1,0,0}, dc[4] = {0,0,1,-1};
            while(!q.empty()) {
                auto [r,c] = q.front(); q.pop();
                for(int k=0;k<4;k++) {
                    int nr=r+dr[k], nc=c+dc[k];
                    if(nr>=0 && nc>=0 && nr<n && nc<m 
                       && !vis[nr][nc] 
                       && heights[nr][nc] >= heights[r][c]) {
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        };

        bfs(qp, pac);
        bfs(qa, atl);

        vector<vector<int>> ans;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
