class Solution {
    void dfs(int node, vector<vector<int>>&adjl,vector<int>&vis)
    {
        vis[node]=1;
        for(auto it: adjl[node])
        {
            if(!vis[it])
            {
                dfs(it,adjl,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<vector<int>> adjl(v);
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(isConnected[i][j]==1)
                {
                    if (isConnected[i][j] == 1 && i != j) { 
                    adjl[i].push_back(j);
                }
            }
        }
        }
        int cnt = 0;
        vector<int> vis(v,0);
        for(int i=0;i<v;i++)
        {
            if(vis[i]!=1)
            {
                cnt++;
                dfs(i,adjl,vis);
            }
        }
         return cnt;
    }
   
    
};