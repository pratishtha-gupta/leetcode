class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
       vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n,1e9);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater <pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,0}});
        //stops,node,dist
        dist[src] = 0;
        while(!pq.empty())
        {
            int stops = pq.top().first;
            int node = pq.top().second.first;
            int wt = pq.top().second.second;
            pq.pop();
            if(stops>k) continue;
            for(auto it: adj[node])
            {
                int adjnode = it.first;
                int edgewt = it.second;
                if(edgewt+wt<dist[adjnode]&&stops<=k)
                {
                    dist[adjnode] = edgewt+wt;
                    pq.push({stops+1,{adjnode,edgewt+wt}});
                }
            }
        }
        if(dist[dst]!=1e9) return dist[dst];
        else
        return -1;
    }
};