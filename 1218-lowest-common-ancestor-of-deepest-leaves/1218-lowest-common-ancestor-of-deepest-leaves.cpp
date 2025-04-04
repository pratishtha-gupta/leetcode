/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, int> depth;  // Store depth of each node
        unordered_map<TreeNode*, TreeNode*> parent;  // Store parent of each node
        int maxDepth = 0;

        // Step 1: DFS to find the depth of each node
        dfs(root, depth, 0, maxDepth);

        // Step 2: BFS to find all deepest leaves
        vector<TreeNode*> deepestLeaves;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (depth[node] == maxDepth) {
                deepestLeaves.push_back(node);
            }

            if (node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }

        // Step 3: Find LCA by moving all deepest leaves upward
        while (deepestLeaves.size() > 1) {
            unordered_set<TreeNode*> seen;
            vector<TreeNode*> newLeaves;

            for (TreeNode* node : deepestLeaves) {
                if (parent.find(node) != parent.end()) {
                    newLeaves.push_back(parent[node]);
                    seen.insert(parent[node]);
                }
            }

            deepestLeaves.assign(seen.begin(), seen.end());
        }

        return deepestLeaves[0];
    }

private:
    void dfs(TreeNode* node, unordered_map<TreeNode*, int>& depth, int d, int& maxDepth) {
        if (!node) return;
        depth[node] = d;
        maxDepth = max(maxDepth, d);
        dfs(node->left, depth, d + 1, maxDepth);
        dfs(node->right, depth, d + 1, maxDepth);
    }
};