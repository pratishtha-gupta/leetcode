class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size()+1,-1);
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1) color[i]=0;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto u:graph[node]){
                    if(color[u]==-1){
                        color[u]=1-color[node];
                        q.push(u);
                    }
                    else if(color[node]==color[u]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};