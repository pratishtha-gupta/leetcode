#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n]; 
        for(int i = 0; i < times.size(); i++) {
            int u = times[i][0] - 1;
            int v = times[i][1] - 1;
            int w = times[i][2];
            adj[u].push_back({v, w});
        }

        // Min heap: {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> timing(n, 1e9);
        timing[k - 1] = 0;
        pq.push({0, k - 1});

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int timeWeight = it.second;
                
                if (time + timeWeight < timing[adjNode]) {
                    timing[adjNode] = time + timeWeight;
                    pq.push({timing[adjNode], adjNode});
                }
            }
        }
        int maxTime = *max_element(timing.begin(), timing.end());
        return (maxTime == 1e9) ? -1 : maxTime;
    }
};
