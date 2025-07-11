class Solution {

bool dfs(vector<vector<int>>& graph,vector<int> &vis,vector<int>&pathvis,vector<int>&check,int node)
{
    vis[node]=1;
    pathvis[node]=1;
    for(auto it: graph[node])
    {
       if(vis[it]!=1)
       {
          if(dfs(graph,vis,pathvis,check,it)==true)
          return true;
       }
       else if(pathvis[it]==1) return true;
    }
    pathvis[node]=0;
    check[node]=1;
    return false;

}
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>vis(v,0),pathvis(v,0),check(v,0);
        for(int i=0;i<v;i++)
        {
            if(!vis[i])
            {
                dfs(graph,vis,pathvis,check,i);
            }
        }
        vector<int> ans;
        for(int i=0;i<v;i++)
        {
           if(check[i]==1) ans.push_back(i);
        }
        return ans;
    }
};