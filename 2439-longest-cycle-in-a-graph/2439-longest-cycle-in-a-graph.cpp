class Solution {
    void dfs(int i, vector<int>&vis, vector<int>&edges,int& ans)
    {
        vis[i]=1;
        int v = edges[i];
        if(v!=-1){
        if(vis[v]==0)
        {
            dfs(v,vis,edges,ans);
        }
        else if(vis[v]==1)
        {
            int len=1;
            for(int i=edges[v];i!=v;i=edges[i]) len++;
            ans = max(ans,len);
        }
        }
         vis[i]=2;
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n,0);
        int ans = -1;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,vis,edges,ans);
            }
        }
        return ans;

    }
};