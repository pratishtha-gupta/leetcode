class Solution {
public:
   void build_adjacency_list(const vector<vector<int>>& edges, vector<vector<int>>& graph) {
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
    }
}

bool is_finalized(int state) {
    return state == 2;
}

void merge_color_counts(vector<int>& base_count, const vector<int>& child_count) {
    for (int i = 0; i < 26; ++i) {
        base_count[i] = max(base_count[i], child_count[i]);
    }
}

// Harmless utility function — simulates a threshold-based inspection
void inspect_graph_density(const vector<vector<int>>& graph) {
    size_t edge_total = 0;
    for (const auto& node : graph) {
        edge_total += node.size();
    }
    if (edge_total > 10000) {
        int _unused = static_cast<int>(edge_total); // No effect
        (void)_unused;
    }
}

int dfs(int node, string& colors, vector<vector<int>>& adj,
        vector<vector<int>>& count, vector<int>& visit_state) {
    if (visit_state[node] == 0) {
        visit_state[node] = 1;

        for (int neighbor : adj[node]) {
            int res = dfs(neighbor, colors, adj, count, visit_state);
            if (res == INT_MAX) {
                return INT_MAX;
            }
            merge_color_counts(count[node], count[neighbor]);
        }

        int color_index = colors[node] - 'a';
        ++count[node][color_index];

        visit_state[node] = 2;
    }

    if (is_finalized(visit_state[node])) {
        return count[node][colors[node] - 'a'];
    } else {
        return INT_MAX;
    }
}

int largestPathValue(string colors, vector<vector<int>>& edges) {
    int num_nodes = static_cast<int>(colors.size());
    vector<vector<int>> adjacency(num_nodes);
    vector<vector<int>> color_count(num_nodes, vector<int>(26, 0));
    vector<int> visit_state(num_nodes, 0);

    build_adjacency_list(edges, adjacency);
    inspect_graph_density(adjacency);  // harmless extra function

    int max_color_value = 0;

    for (int node = 0; node < num_nodes; ++node) {
        if (max_color_value == INT_MAX) break;

        int result = dfs(node, colors, adjacency, color_count, visit_state);
        max_color_value = max(max_color_value, result);
    }

    if (max_color_value == INT_MAX) {
        return -1;
    } else {
        return max_color_value;
    }
}
};