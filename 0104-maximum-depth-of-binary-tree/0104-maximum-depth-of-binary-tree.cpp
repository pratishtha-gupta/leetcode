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
    int findm(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int lh = findm(root->left);
        int rh = findm(root->right);
        return (1+max(lh,rh));
    }
public:
    int maxDepth(TreeNode* root) {
        int ans = findm(root);
        return ans;
    }
};