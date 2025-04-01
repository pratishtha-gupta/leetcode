class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            graph[i] = {};
        }
        for (const auto& pre : prerequisites) {
            int u = pre[0], v = pre[1];
            graph[u].push_back(v);
        }
        vis.assign(numCourses, 0);
        for (int node = 0; node < numCourses; node++) {
            if (vis[node] == 0) { 
                if (!NoDetectCycle(node, graph)) 
                    return {}; 
            }
        }

        return orderingCourses;
    }

private:
    vector<int> vis; 
    vector<int> orderingCourses;

    bool NoDetectCycle(int node, unordered_map<int, vector<int>>& graph) {
        vis[node] = 2; 
        for (int neigh : graph[node]) {
            if (vis[neigh] == 2) {
                return false; 
            } else if (vis[neigh] == 1) {
                continue;
            } else if (!NoDetectCycle(neigh, graph)) {
                return false;
            }
        }
        vis[node] = 1;
        orderingCourses.push_back(node);
        return true;
    }
};
