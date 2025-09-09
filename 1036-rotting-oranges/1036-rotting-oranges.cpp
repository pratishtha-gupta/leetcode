class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        int time=0;
        int count=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                }
                else if(grid[i][j]==1)
                count++;
            }
        }
        int delrow[4]={1,0,-1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()&&count>0)
        {
            time++;
            int size= q.size();
            for(int i=0;i<size;i++)
            {
           auto it = q.front();
           int row = it.first;
           int col = it.second;
           q.pop();
           for(int i=0;i<4;i++)
           {
               int nrow = row+delrow[i];
               int ncol = col+delcol[i];
               if(nrow<n&&ncol<m&&nrow>=0&&ncol>=0&&grid[nrow][ncol]==1&&vis[nrow][ncol]==0)
               {
                   grid[nrow][ncol]=2;
                   vis[nrow][ncol]=1;
                   q.push({nrow,ncol});
                   count--;
               }
           }
            }
        }
        if(count==0) return time;
        else return -1;
    }
};