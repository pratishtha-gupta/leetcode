class Solution {
private:
    void dfs(int r,int c,int delrow[],int delcol[],vector<vector<int>> &vis,vector<vector<int>>& grid)
    {
        vis[r][c]=1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<4;i++)
        {
            int row = r+delrow[i];
            int col = c+delcol[i];
            if(row>=0&&row<m&&col>=0&&col<n&&!vis[row][col]&&grid[row][col]==1)
            {
                vis[row][col]=1;
                dfs(row,col,delrow,delcol,vis,grid);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt =0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int j=0;j<n;j++)
        {
            if(!vis[0][j]&&grid[0][j]==1)
            {
                dfs(0,j,delrow,delcol,vis,grid);
            }
            if(!vis[m-1][j]&&grid[m-1][j]==1)
            {
                dfs(m-1,j,delrow,delcol,vis,grid);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0]&&grid[i][0]==1)
            {
                dfs(i,0,delrow,delcol,vis,grid);
            }
            if(!vis[i][n-1]&&grid[i][n-1]==1)
            {
                dfs(i,n-1,delrow,delcol,vis,grid);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                cnt++;
            }
        }
        return cnt;
    }
};