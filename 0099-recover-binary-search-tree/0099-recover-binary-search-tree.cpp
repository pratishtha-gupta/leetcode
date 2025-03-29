class Solution {
    void inorder(TreeNode* root, vector<int> &v) {
        if (root == nullptr) return;
        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
    }

    void inorder1(TreeNode* root, int num1, int num2, TreeNode*& node1, TreeNode*& node2) {
        if (root == nullptr) return;
        
        inorder1(root->left, num1, num2, node1, node2);
        
        if (root->val == num1) node1 = root;
        if (root->val == num2) node2 = root;
        
        inorder1(root->right, num1, num2, node1, node2);
    }

    void swapnodes(TreeNode* root, int num1, int num2) {
        TreeNode *node1 = nullptr, *node2 = nullptr;
        inorder1(root, num1, num2, node1, node2);
        
        if (node1 && node2) swap(node1->val, node2->val);  // Ensure both nodes exist before swapping
    }

public:
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int num1 = -1, num2 = -1;
        
        // Find the first misplaced element
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i] > v[i + 1]) {
                num1 = v[i];
                break;
            }
        }
        
        // Find the second misplaced element
        for (int i = v.size() - 1; i > 0; i--) {
            if (v[i - 1] > v[i]) {
                num2 = v[i];
                break;
            }
        }
        
        swapnodes(root, num1, num2);
    }
};
