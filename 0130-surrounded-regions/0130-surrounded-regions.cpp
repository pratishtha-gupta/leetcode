class Solution {
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<char>>&v,int delrow[],int delcol[])
    {
        int m = v.size();
        int n = v[0].size();
        
        vis[r][c]=1;
        for(int i=0;i<4;i++)
        {
            int row = delrow[i]+r;
            int col = delcol[i]+c;
            if(row>=0&&row<m&&col>=0&&col<n&&v[row][col]=='O'&&!vis[row][col])
            {
                dfs(row,col,vis,v,delrow,delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        //first row
        for(int j=0;j<n;j++)
        {
            if(v[0][j]=='O'&&!vis[0][j])
            {
                dfs(0,j,vis,v,delrow,delcol);
            }
            if(v[m-1][j]=='O'&&!vis[m-1][j])
            {
                dfs(m-1,j,vis,v,delrow,delcol);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0]&&v[i][0]=='O')
            {
                dfs(i,0,vis,v,delrow,delcol);
            }
            //last column
            if(!vis[i][n-1]&&v[i][n-1]=='O')
            {
                dfs(i,n-1,vis,v,delrow,delcol);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==0&&v[i][j]=='O')
                {
                    v[i][j]= 'X';
                }
            }
        }
    }
};