class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> ans(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
                else
                vis[i][j]=0;
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            q.pop();
            ans[row][col]=step;
            for(int i=0;i<4;i++)
            {
                int newrow = row+delrow[i];
                int newcol = col+delcol[i];
                if(newrow>=0&&newrow<m&&newcol>=0&&newcol<n&&vis[newrow][newcol]==0)
                {
                    vis[newrow][newcol]=1;
                    q.push({{newrow,newcol},step+1});
                }
            }
        }
        return ans;
    }
};